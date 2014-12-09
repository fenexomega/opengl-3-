#include<iostream>
#include "Common/Systems.h"
#include <GL/glew.h>

using namespace std;

int main()
{
	DisplaySDL2 display(0,0,1024,768,"Título");	
	
	GLfloat vertices[] = 
	{
		0.0f,1.0f,0.0f, 1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f, 0.0f,1.0f,0.0f,
		-1.0f,0.0f,0.0f, 0.0f,0.0f,1.0f,
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

	program.BindFragDataLocation("Color",0);
	
	program.AttachShader(vertex);
	program.AttachShader(fragment);

	program.Link();
	program.Use();

	GLuint posAttrib = program.getAttrib("pos");
	GLuint colorAttrib = program.getAttrib("Color");

	glVertexAttribPointer(posAttrib,3,GL_FLOAT,GL_FALSE,6*sizeof(GLfloat),0);
	glVertexAttribPointer(colorAttrib,3,GL_FLOAT,GL_FALSE,6*sizeof(GLfloat),(GLvoid  *) (3*(sizeof(GLfloat))));
	
	glEnableVertexAttribArray(posAttrib);
	glEnableVertexAttribArray(colorAttrib);

	while(!display.UserWannaQuit())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0,0,0,1);	
		
		glDrawArrays(GL_TRIANGLES,0,3);

		display.SwapBuffers();
	}

	return 0;
}
