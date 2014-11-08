#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <fstream>
using namespace std;


SDL_Window * window;

//uma array de 3 vetores que representam vertices

// Shader sources


const char * loadShader(string filepath)
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

    // Create Vertex Array Object
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create a Vertex Buffer Object and copy the vertex data to it
    GLuint vbo;
    glGenBuffers(1, &vbo);

    GLfloat vertices[] = {
        -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // Top-left
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // Top-right
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f  // Bottom-left
    };

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create an element array
    GLuint ebo;
    glGenBuffers(1, &ebo);

    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);


	
    // Create and compile the vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar * vertexSource = loadShader("vertexshader.glsl");
	cout << "coteúdo: " <<  vertexSource << endl;
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

	GLint _compiled = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &_compiled);
	if (!_compiled)
	{
		GLint length;
	  	GLchar* log;
	  	glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
		log = new GLchar[length];
	    glGetShaderInfoLog(vertexShader, length, &length, log);
		std::cerr << "!!! Compile log = " << log << std::endl;
		delete log;
	}

    const GLchar * fragmentSource = loadShader("fragmentshader.glsl");
    // Create and compile the fragment shader
	cout << "coteúdo: " <<  fragmentSource << endl;
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
	
	 _compiled = 0;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &_compiled);
	if (!_compiled)
	{
		GLint length;
	  	GLchar* log;
	  	glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
		log = new GLchar[length];
	    glGetShaderInfoLog(fragmentShader, length, &length, log);
		std::cerr << "!!! Compile log = " << log << std::endl;
		delete log;
	}

    // Link the vertex and fragment shader into a shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);

    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));


	SDL_Event windowEvent;

	while(true)
	{
		if(SDL_PollEvent(&windowEvent))
		{
			if(windowEvent.type == SDL_QUIT) break;
		}
	
	 // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a rectangle from the 2 triangles using 6 indices
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
		SDL_GL_SwapWindow(window);
	}

	glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);

    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);

    glDeleteVertexArrays(1, &vao);

	SDL_Quit();

	return 0;
}
