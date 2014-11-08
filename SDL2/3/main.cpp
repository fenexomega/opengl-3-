#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <fstream>
using namespace std;


SDL_Window * window;

//uma array de 3 vetores que representam vertices

// Shader sources


const char * LoadFileIntoString(string filepath)
{
	string *content = new string;
	ifstream file(filepath.c_str(), ios::in);

	if(!file.is_open())
	{
		cout << "Couldn't open file " << filepath;
		return NULL;
	}

	string line;
	do
	{
		getline(file,line);
			*content += line + "\n"; 			
	}while(!file.eof());
	
	file.close();

	return content->c_str();
}

void ShowShaderLog(GLuint shader)
{

	GLint _compiled = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &_compiled);
	if (!_compiled)
	{
		GLint length;
	  	GLchar* log;
	  	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		log = new GLchar[length];
	    glGetShaderInfoLog(shader, length, &length, log);
		std::cerr << "!!! Compile log = " << log << std::endl;
		delete log;
	}
	
}

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	window = SDL_CreateWindow("Janela", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1024,768,SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	SDL_GLContext context = SDL_GL_CreateContext(window);

 // Initialize GLEW
    glewExperimental = GL_TRUE;
    glewInit();

	float vertices[]{
		0.0f, 0.5f,
		-0.5f,-0.5f,
		0.5f,-0.5f
	};

	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	//Vertex Buffer
	GLuint vbo;
	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER,vbo);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

	//carregar Shader de vertex
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar * vertexSource = LoadFileIntoString("vertexshader.glsl");
	glShaderSource(vertexShader,1,&vertexSource,NULL);
	glCompileShader(vertexShader);
	ShowShaderLog(vertexShader);	

	//Carregar Shader de fragment
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	const GLchar * fragmentSource = LoadFileIntoString("fragmentshader.glsl");
	glShaderSource(fragmentShader,1,&fragmentSource,NULL);
	glCompileShader(fragmentShader);
	ShowShaderLog(fragmentShader);

//Carregar Programa
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram,vertexShader);
	glAttachShader(shaderProgram,fragmentShader);

	glBindFragDataLocation(shaderProgram,0,"outColor");

	//Linkar shaders ao programa
	glLinkProgram(shaderProgram);
	//Usar programa
	glUseProgram(shaderProgram);

	//get vec2 from shaderProgram
	GLuint posAttrib = glGetAttribLocation(shaderProgram,"position");
	glVertexAttribPointer(posAttrib,2,GL_FLOAT, GL_FALSE,0,0);


	glEnableVertexAttribArray(posAttrib);


	SDL_Event windowEvent;

	while(true)
	{
		if(SDL_PollEvent(&windowEvent))
		{
			if(windowEvent.type == SDL_QUIT) break;
		}
	
		glDrawArrays(GL_TRIANGLES,0,3);	
		SDL_GL_SwapWindow(window);
	}

    glDeleteBuffers(1, &vbo);

	glDetachShader(vertexShader,shaderProgram);
	glDetachShader(fragmentShader,shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	SDL_Quit();

	return 0;
}
