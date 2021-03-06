#include "DisplaySDL2.h"
#include "DisplaySFML.h"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SDL2/SDL_image.h>

using namespace std;

char * vertexShaderSource = {
    "#version 140\n"
    "in vec3 pos;"
    "in vec3 color;"
    "out vec3 Color;"
    "in vec2 texc;"
    "out vec2 Texcoord;"
	"uniform mat4 model;"
	"uniform mat4 view;"
	"uniform mat4 proj;"
    "void main(){"
    "Color = vec3(color);"
    "gl_Position = proj* view * model * vec4(pos,1.0) ;"
	"Texcoord = texc;"
	"}"
};

char * fragmentShaderSource = 
{
    "#version 140\n"
    "out vec4 outColor;"
    "in vec3 Color;"
    "uniform sampler2D tex;"
	"in vec2 Texcoord;"
    "void main(){"
    "outColor = texture(tex,Texcoord);}"
};


int main()
{
	glm::mat4 trans;

    DisplaySDL2 display(0,0,1024,768,"Olá mundo");
    GLchar * glVersion = (GLchar *)glGetString(GL_VERSION);
    cout << glVersion << endl;

    SDL_Surface *image;

    image = IMG_Load("sample.png");
    int Mode;
    Mode = GL_RGB;
    if(image->format->BytesPerPixel == 4)
    {
        std::cout << "RGBA!" << std::endl;
        Mode = GL_RGBA;
    }

	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
	};


    GLuint vao;
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);



    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderID,1,&vertexShaderSource,0);
    glCompileShader(vertexShaderID);


    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderID,1,&fragmentShaderSource,0);
    glCompileShader(fragmentShaderID);

    GLuint program = glCreateProgram();

    glAttachShader(program,vertexShaderID);
    glAttachShader(program,fragmentShaderID);

    glBindFragDataLocation(program,0,"outColor");

	glEnable(GL_DEPTH_TEST);


    glLinkProgram(program);
    glUseProgram(program);

    GLuint posAttrib = glGetAttribLocation(program,"pos");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib,3,GL_FLOAT,GL_FALSE,8*sizeof(float),0);

    GLuint colorAttrib = glGetAttribLocation(program,"color");
    glEnableVertexAttribArray(colorAttrib);
    glVertexAttribPointer(colorAttrib ,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(GLvoid *) (3*sizeof(float)));

    GLuint texAttrib = glGetAttribLocation(program,"texc");
    glEnableVertexAttribArray(texAttrib);
    glVertexAttribPointer(texAttrib,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(GLvoid *) (6*sizeof(float)) );

	GLint uniTrans = glGetUniformLocation(program,"model");
	GLint uniView  = glGetUniformLocation(program,"view");
	GLint uniProj  = glGetUniformLocation(program,"proj");

	glm::mat4 view = glm::lookAt(
			glm::vec3(1.2f,1.2f,1.2f), //Position of the Camera
			glm::vec3(  0,    0,   0), //Where camera is looking
			glm::vec3(0.0f,0.0f,1.0f)); //Up vector

	glUniformMatrix4fv(uniView,1,GL_FALSE,glm::value_ptr(view));

	glm::mat4 proj = glm::perspective(45.0f,display.getRatio(),0.1f,100.0f);
	glUniformMatrix4fv(uniProj,1,GL_FALSE,glm::value_ptr(proj));
	

    GLuint tex;
    glGenTextures(1,&tex);
    glBindTexture(GL_TEXTURE_2D,tex);

    glTexImage2D(GL_TEXTURE_2D,0,Mode,image->w,image->h,0,Mode,GL_UNSIGNED_BYTE,image->pixels );

	SDL_FreeSurface(image);
	
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    while(!display.UserWannaQuit())
    {

        display.CleanScreen(0,0,0,1.0f);
        display.Delay(1000/60);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		trans = glm::rotate(trans,1.0f,glm::vec3(0.0f,0.0f,1.0f));
		glUniformMatrix4fv(uniTrans,1,GL_FALSE,glm::value_ptr(trans));
		
		glDrawArrays(GL_TRIANGLES,0,36);	


        display.SwapBuffers();
    }


    glDeleteProgram(program);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);



    glDeleteTextures(1,&tex);
    glDeleteBuffers(1,&vbo);
    glDeleteBuffers(1,&vao);

    display.Quit();



    return EXIT_SUCCESS;

}

//GLuint posAttrib = glGetAttribLocation(program,"pos");
//glEnableVertexAttribArray(posAttrib);
//glVertexAttribPointer(posAttrib,2,GL_FLOAT,GL_FALSE,0,0);
