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
	glm::mat4 model;
	glEnable(GL_DEPTH_TEST);

	GLfloat vertices[] = {
		 0.5f, 0.5f, 0.5f, 1.0f,0.0f,0.0f, 1.0f,1.0f, //0
		-0.5f, 0.5f, 0.5f, 0.0f,1.0f,0.0f, 0.0f,1.0f, //1
		-0.5f,-0.5f, 0.5f, 0.0f,0.0f,1.0f, 0.0f,0.0f, //2 
		 0.5f,-0.5f, 0.5f, 1.0f,1.0f,1.0f, 1.0f,0.0f, //3
	
		 0.5f, 0.5f,-0.5f, 1.0f,0.0f,0.0f, 1.0f,1.0f, //4
		-0.5f, 0.5f,-0.5f, 0.0f,1.0f,0.0f, 0.0f,1.0f, //5
		-0.5f,-0.5f,-0.5f, 0.0f,0.0f,1.0f, 0.0f,0.0f, //6
	     0.5f,-0.5f,-0.5f, 1.0f,1.0f,1.0f, 1.0f,0.0f, //7
		 
		 0.5f, 0.5f, 0.5f, 1.0f,0.0f,0.0f, 1.0f,1.0f, //8
		-0.5f, 0.5f, 0.5f, 0.0f,1.0f,0.0f, 0.0f,1.0f, //9
		-0.5f, 0.5f,-0.5f, 0.0f,0.0f,1.0f, 0.0f,0.0f, //10
	     0.5f, 0.5f,-0.5f, 1.0f,1.0f,1.0f, 1.0f,0.0f, //11
		 
		 0.5f,-0.5f, 0.5f, 1.0f,0.0f,0.0f, 1.0f,1.0f, //12
		-0.5f,-0.5f, 0.5f, 0.0f,1.0f,0.0f, 0.0f,1.0f, //13
		-0.5f,-0.5f,-0.5f, 0.0f,0.0f,1.0f, 0.0f,0.0f, //14
	     0.5f,-0.5f,-0.5f, 1.0f,1.0f,1.0f, 1.0f,0.0f, //15

		-0.5f, 0.5f, 0.5f, 1.0f,0.0f,0.0f, 1.0f,1.0f, //16
		-0.5f, 0.5f,-0.5f, 0.0f,1.0f,0.0f, 0.0f,1.0f, //17
		-0.5f,-0.5f,-0.5f, 0.0f,0.0f,1.0f, 0.0f,0.0f, //18
	    -0.5f,-0.5f, 0.5f, 1.0f,1.0f,1.0f, 1.0f,0.0f, //19

		 0.5f, 0.5f, 0.5f, 1.0f,0.0f,0.0f, 1.0f,1.0f, //20
		 0.5f, 0.5f,-0.5f, 0.0f,1.0f,0.0f, 0.0f,1.0f, //21
		 0.5f,-0.5f,-0.5f, 0.0f,0.0f,1.0f, 0.0f,0.0f, //22
	     0.5f,-0.5f, 0.5f, 1.0f,1.0f,1.0f, 1.0f,0.0f, //23
	};


	GLuint elements[] = {
		0,1,2,
		0,2,3,

		4,5,6,
		4,6,7,

		8,9,10,
		8,10,11,

		12,13,14,
		12,14,15,

		16,17,18,
		16,18,19,

		20,21,22,
		20,22,23,

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

	GLuint tex;
	glGenTextures(1,&tex);
	glBindTexture(GL_TEXTURE_2D,tex);
	
	SDL_Surface *img = IMG_Load("texture.jpg");
	
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGB,GL_UNSIGNED_BYTE,img->pixels);

	SDL_FreeSurface(img);

	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

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
	GLuint texPosAttrib = program.EnableAttrib("texPos");

	GLuint uniformModel = glGetUniformLocation(program.getId(),"model");
	GLuint uniformView  = glGetUniformLocation(program.getId(),"view");
	GLuint uniformProj  = glGetUniformLocation(program.getId(),"proj");
	glVertexAttribPointer(posAttrib,3,GL_FLOAT,GL_FALSE,8*sizeof(GLfloat),0);
	glVertexAttribPointer(colorAttrib,3,GL_FLOAT,GL_FALSE,8*sizeof(GLfloat),(void *) (3*sizeof(GLfloat)));
	glVertexAttribPointer(texPosAttrib,2,GL_FLOAT,GL_FALSE,8*sizeof(GLfloat),(void *) (6*sizeof(GLfloat)));

	glm::mat4 proj = glm::perspective(45.0f,display.getRatio(),0.1f,100.0f);
	glm::mat4 view = glm::lookAt( glm::vec3(0,1,3.0f),
								  glm::vec3(0,0,0),
								  glm::vec3(0,1.0f,0));
	glViewport(0,0,display.getWidth(),display.getHeight());

	glUniformMatrix4fv(uniformProj,1,GL_FALSE,glm::value_ptr(proj));
	glUniformMatrix4fv(uniformView,1,GL_FALSE,glm::value_ptr(view));

	float i = 1;
    while(!display.UserWannaQuit())
    {

		model = glm::rotate(model,i,glm::vec3(0,1,0));
		glUniformMatrix4fv(uniformModel,1,GL_FALSE,glm::value_ptr(model));

        display.Delay(1000/60);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        display.CleanScreen(0,0,0,1.0f);

		glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);

        display.SwapBuffers();
    }

		
	glDeleteBuffers(1,&vbo);
	glDeleteVertexArrays(1,&vao);

    display.Quit();



    return EXIT_SUCCESS;

}
