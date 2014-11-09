#include "../common/display.h"
#include <iostream>
#include <glm/glm.hpp>

char * vertexShader =
{
	"# version 150\n"
	"in vec2 position;"
	"void main(){"
	"gl_Position = vec4(position,0,1.0);"
	"}"
};

char * fragmentShader =
{
	"#version 150\n"
	"out vec4 outColor;"
	"void main(){"
	"outColor = vec4(1.0,1.0,1.0,1.0);"
	"}"
};

int main()
{
	Display::initSDLandGL();
	Display display(0,0,1024,768,"Janela SDL");

	float vertices[]{
		 0.0f, 1.0f,
		-1.0f, 0.0f,
		 1.0,  0.0f
	};

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	
	GLuint vbo;
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);	

	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID,1,&vertexShader,NULL);
	glCompileShader(vertexShaderID);
	
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID,1,&fragmentShader,NULL);
	glCompileShader(fragmentShaderID);

	GLuint program = glCreateProgram();
	glAttachShader(program,vertexShaderID);
	glAttachShader(program,fragmentShaderID);
	
	glBindFragDataLocation(program,0,"outColor");
	
	glLinkProgram(program);
	glUseProgram(program);

	GLuint posAttrib = glGetAttribLocation(program,"position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib,2,GL_FLOAT,GL_FALSE,2*sizeof(float),0);
	
	while(!display.UserWannaQuit())
	{
		display.CleanScreen(0,0,0,1.0);
		glDrawArrays(GL_POINTS,0,3);	
		display.SwapBuffers();
	}
	
	SDL_Quit();
}
