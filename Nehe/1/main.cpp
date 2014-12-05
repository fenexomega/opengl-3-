#include "../Common/DisplaySDL2.h"
#include "../Common/Shader.h"
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SDL2/SDL_image.h>

#define PRINT(x) std::cout << x << std::endl

using namespace std;

void PrintGLInfo()
{
	vector<GLchar *> glinfo;

    glinfo.push_back((GLchar *)glGetString(GL_VERSION));
    glinfo.push_back((GLchar *)glGetString(GL_SHADING_LANGUAGE_VERSION));
	glinfo.push_back((GLchar *)glGetString(GL_VENDOR));
    glinfo.push_back((GLchar *)glGetString(GL_RENDERER));
	
	for(auto i : glinfo)
	{
		PRINT(i);
	}

}

int main()
{

    DisplaySDL2 display(0,0,1024,768,"Olá mundo");
	PrintGLInfo();


	GLfloat vertices[] = {
		 0.5f,0.5f,  1.0f,0.0f,0.0f,
		-0.5f,0.5f,  0.0f,1.0f,0.0f,
		-0.5f,-0.5f, 0.0f,0.0f,1.0f,
	};

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	
	GLuint vbo;
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);


	Shader vertex("vertex.glsl",GL_VERTEX_SHADER);
	Shader fragment("fragment.glsl",GL_FRAGMENT_SHADER);
	
	GLuint program = glCreateProgram();

	glAttachShader(program,vertex.getShaderId());
	glAttachShader(program,fragment.getShaderId());
	
	glBindFragDataLocation(program,0,"outColor");


	glLinkProgram(program);
	glUseProgram(program);


	GLuint posAttrib = glGetAttribLocation(program,"pos");
	GLuint colorAttrib = glGetAttribLocation(program,"color");
	glEnableVertexAttribArray(posAttrib);
	glEnableVertexAttribArray(colorAttrib);

	glVertexAttribPointer(posAttrib,2,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),0);
	glVertexAttribPointer(colorAttrib,3,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),(void *) (2*sizeof(GLfloat)));



    while(!display.UserWannaQuit())
    {

        display.Delay(1000/60);
		glClear(GL_COLOR_BUFFER_BIT  );
        display.CleanScreen(0,0,0,1.0f);

		glDrawArrays(GL_TRIANGLES,0,3);

        display.SwapBuffers();
    }

	glDeleteProgram(program);

	glDeleteBuffers(1,&vbo);
	glDeleteVertexArrays(1,&vao);

    display.Quit();



    return EXIT_SUCCESS;

}
