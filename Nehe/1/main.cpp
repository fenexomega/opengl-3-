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
	"uniform vec3 overrideColor;"
    "void main(){"
    "Color =  overrideColor * color;"
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
    "outColor = vec4(Color,1.0) * texture(tex,Texcoord);}"
};

char *vertexShader2DSource =
{
	"#version 140\n"
	"in vec2 pos;"
	"in vec2 texcoord;"
	"out vec2 Texcoord;"
	"void main(){"
	"Texcoord = texcoord;"
	"gl_Position = vec4(pos,0.0,1.0);"
	"}"
};

int main()
{
	glm::mat4 trans;

    DisplaySDL2 display(0,0,1024,768,"Olá mundo");
    GLchar * glVersion = (GLchar *)glGetString(GL_VERSION);
    cout << glVersion << endl;



    while(!display.UserWannaQuit())
    {

        display.Delay(1000/60);
        display.CleanScreen(1,1,1,1.0f);


        display.SwapBuffers();
    }




    display.Quit();



    return EXIT_SUCCESS;

}

//GLuint posAttrib = glGetAttribLocation(program,"pos");
//glEnableVertexAttribArray(posAttrib);
//glVertexAttribPointer(posAttrib,2,GL_FLOAT,GL_FALSE,0,0);
