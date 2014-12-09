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

	GLuint elements[] = {
		0,1,2,
		0,2,3,
	};

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	
	GLuint vbo;
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
	
	GLuint ebo;
	glGenBuffers(1,&ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elements),elements,GL_STATIC_DRAW);

	Shader vertex("vertex.glsl",GL_VERTEX_SHADER);
	Shader fragment("fragment.glsl",GL_FRAGMENT_SHADER);

	Program program;
	program.AttachShader(vertex);
	program.AttachShader(fragment);

	program.BindFragDataLocation("outColor",0);

	program.Link();
	program.Use();

	GLuint posAttrib = program.EnableAttrib("pos");
	GLuint colorAttrib = program.EnableAttrib("color");

	glVertexAttribPointer(posAttrib,2,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),0);
	glVertexAttribPointer(colorAttrib,3,GL_FLOAT,GL_FALSE,5*sizeof(GLfloat),(void *) (2*sizeof(GLfloat)));



    while(!display.UserWannaQuit())
    {

        display.Delay(1000/60);
		glClear(GL_COLOR_BUFFER_BIT  );
        display.CleanScreen(0,0,0,1.0f);

		glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);

        display.SwapBuffers();
    }

		
	glDeleteBuffers(1,&vbo);
	glDeleteVertexArrays(1,&vao);

    display.Quit();



    return EXIT_SUCCESS;

}
