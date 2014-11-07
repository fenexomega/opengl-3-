#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


SDL_Window * window;

//uma array de 3 vetores que representam vertices
GLfloat vertices[] = {
	0.0f,1.0f,0.0f,
	-1.0f,-1.0f,0.0f,
	1.0f,-1.0f,0.0f
};

GLuint LoadShaders(const char *vertex_file_path, const char *fragment_file_path)
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	string VertexShaderCode;
	string FragmentShaderCode;

	ifstream VertexShaderStream(vertex_file_path,ios::in);
	if(VertexShaderStream.is_open())
	{
		string line = "";
		while(getline(VertexShaderStream,line))
			VertexShaderCode += line + "\n";
		VertexShaderStream.close();		
	}
	
	ifstream FragmentShaderStream(fragment_file_path,ios::in);
	if(FragmentShaderStream.is_open())
	{
		string line = "";
		while(getline(FragmentShaderStream,line))
			FragmentShaderCode += line + "\n";
		FragmentShaderStream.close();		
	}
	
	GLint result = GL_FALSE;
	int InfoLogLenght;

	//Compilar Shader
	cout << "Compilling shader: " << vertex_file_path << endl;
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(vertexShaderID,1,&VertexSourcePointer,NULL);
	glCompileShader(vertexShaderID);
	cout << VertexShaderCode << endl;

	// Check Vertex Shader
	glGetShaderiv(vertexShaderID,GL_COMPILE_STATUS,&result);
	glGetShaderiv(vertexShaderID,GL_INFO_LOG_LENGTH,&InfoLogLenght);
	vector<char> vertexShaderErrorMessage(InfoLogLenght);
	glGetShaderInfoLog(vertexShaderID,InfoLogLenght,NULL,&vertexShaderErrorMessage[0]);
	cout << &vertexShaderErrorMessage[0] << endl;

	//Compile fragment Shader
	cout << "Compilling Shader: " << fragment_file_path << endl;
	char const * fragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(fragmentShaderID,1,&fragmentSourcePointer,NULL);
	glCompileShader(fragmentShaderID);
	cout << FragmentShaderCode << endl;

	//Check Fragment Shader
	glGetShaderiv(fragmentShaderID,GL_COMPILE_STATUS,&result);
	glGetShaderiv(fragmentShaderID,GL_INFO_LOG_LENGTH,&InfoLogLenght);
	vector<char> fragmentShaderErrorMessage(InfoLogLenght);
	glGetShaderInfoLog(fragmentShaderID,InfoLogLenght,NULL,&fragmentShaderErrorMessage[0]);
	cout << &fragmentShaderErrorMessage[0] << endl;

	//Link to the program
	cout << "Linking program" << endl;
	GLuint programID = glCreateProgram();
	glAttachShader(programID,vertexShaderID);
	glAttachShader(programID,fragmentShaderID);
	glLinkProgram(programID);

	// check the program
	glGetProgramiv(programID,GL_LINK_STATUS,&result);
	glGetProgramiv(programID,GL_INFO_LOG_LENGTH,&InfoLogLenght);
	vector<char> ProgramErrorMessage(InfoLogLenght);
	glGetProgramInfoLog(programID,InfoLogLenght,NULL,&ProgramErrorMessage[0]);
	cout << ProgramErrorMessage[0] << endl;

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return programID;

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

	glewExperimental = true;
	glewInit();

// TUTORIAL PART

	GLuint VertexArrayID;
	glGenVertexArrays(1,&VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLuint vertexBuffer;

	glGenBuffers(1,&vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);


	GLuint programID = LoadShaders("vertexshader.glsl","fragmentshader.glsl");

// ENDS THERE



	SDL_Event windowEvent;

	while(true)
	{
		if(SDL_PollEvent(&windowEvent))
		{
			if(windowEvent.type == SDL_QUIT) break;
		}
	
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0f,0.0,0.0,1.0f);
		
		glUseProgram(programID);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER,vertexBuffer);
		glVertexAttribPointer(
				0,
				3,
				GL_FLOAT,
				GL_FALSE,
				0,
				0);
		glDrawArrays(GL_TRIANGLES,0,3);
		
		glDisableVertexAttribArray(0);

		glUseProgram(0);
		SDL_GL_SwapWindow(window);
	}


	SDL_GL_DeleteContext(context);

	SDL_Quit();

	return 0;
}
