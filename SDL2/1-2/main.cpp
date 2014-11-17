#include "../common/displaySDL2.hpp"
#include <iostream>
#include <glm/glm.hpp>
#include "../common/Shader.hpp"
int main()
{
	DisplaySDL2 display(0,0,1024,764,"Daora a vida");
	Shader vertex("vertexShader.glsl",GL_VERTEX_SHADER);
	Shader fragment("fragmentShader.glsl",GL_FRAGMENT_SHADER);

	float vertices[] = {
		0.0f,1.0,0.0f,
		-1.0f,0.0f,0.0f,
		1.0f,0.0f,0.0f
	};

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);


	GLuint program = glCreateProgram();
	glAttachShader(program,vertex.getShaderID());
	glAttachShader(program,fragment.getShaderID());

	glBindFragDataLocation(program,0,"outColor");

	glLinkProgram(program);
	glUseProgram(program);


	GLuint posAttrib = glGetAttribLocation(program,"position");
	glEnableVertexAttribArray(posAttrib);
	glVertexAttribPointer(posAttrib,2,GL_FLOAT,GL_FALSE,3*sizeof(float),0);
	while(!display.UserWannaQuit())
	{
		display.CleanScreen(0,0,0,1);
		display.Delay(1000/24);
		glDrawArrays(GL_TRIANGLES,0,3);

		display.SwapBuffers();
	}

	glDetachShader(program,vertex.getShaderID());
	vertex.~Shader();
	glDetachShader(program,fragment.getShaderID());
	fragment.~Shader();
	glDeleteProgram(program);
	display.Quit();

	return EXIT_SUCCESS;
}
