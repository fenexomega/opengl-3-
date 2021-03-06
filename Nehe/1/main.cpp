#include "../Common/Systems.h"
#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SDL2/SDL_image.h>


using namespace std;


int main()
{

    DisplaySDL2 display(0,0,1024,768,"Olá mundo");


	GLfloat vertices[] = {
		 0.5f,0.5f,  1.0f,0.0f,0.0f,
		-0.5f,0.5f,  0.0f,1.0f,0.0f,
		-0.5f,-0.5f, 0.0f,0.0f,1.0f,
		 0.5f,-0.5f, 1.0f,1.0f,1.0f
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

	Program program;
	program.AttachShader(vertex);
	program.AttachShader(fragment);

	program.BindFragDataLocation("outColor",0);

	program.Link();
	program.Use();

	GLuint posAttrib = program.getAttrib("pos");
	GLuint colorAttrib = program.getAttrib("color");

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


	glDeleteBuffers(1,&vbo);
	glDeleteVertexArrays(1,&vao);

    display.Quit();



    return EXIT_SUCCESS;

}
