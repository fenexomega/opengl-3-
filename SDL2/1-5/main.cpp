#include "../common/displaySDL2.hpp"
#include "../common/displaySFML.hpp"
#include <iostream>
using namespace std;

char * vertexShaderSource = {
	"#version 140\n"
	"in vec3 pos;"
	"void main(){"
	"gl_Position = vec4(pos,1.0); }"
};

char * fragmentShaderSource = 
{
	"#version 140\n"
	"out vec4 Color;"
	"void main(){"
	"Color = vec4(1.0,1.0,1.0);}"
};

int main()
{
	DisplaySDL2 display(0,0,1024,768,"Olá mundo");
	GLchar * glVersion = (GLchar *)glGetString(GL_VERSION);
	cout << glVersion << endl;


	GLfloat vertices [] = {
		0.0f,1.0f,
		-1.0f,0.0f,
		1.0f,0.0f
	};

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,0);

	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID,1,&vertexShaderSource,0);
	glCompileShader(vertexShaderID);


	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID,1,&fragmentShaderSource,0);
	glCompileShader(fragmentShaderID);

	GLuint program = glCreateProgram();

	glAttachShader(program,vertexShaderID);
	glAttachShader(program,fragmentShaderID);

	GLuint posAttrib = glGetAttribLocation(program,"pos");
	
	glLinkProgram(program);
	glUseProgram(program);

	


	while(!display.UserWannaQuit())
	{
		display.CleanScreen(0,0,0,1.0f);

		display.SwapBuffers();
	}

	display.Quit();
	


	return EXIT_SUCCESS;

}
