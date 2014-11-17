#ifndef DISPLAYSDL2_H
#define DISPLAYSDL2_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>



class DisplaySDL2
{
private:
	unsigned int x,y;
	unsigned int width,height;
	std::string title;
	SDL_Window *window;
	SDL_GLContext context;
	bool initGL()
	{
		bool flag = true;
		if(SDL_Init(SDL_INIT_VIDEO) != 0)
			flag = false;
		
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3.3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
		return flag;
	}
public:

	DisplaySDL2(int x,int y, int width, int height, std::string title)
	{
		this->x 	 = x;
		this->y  	 = y;
		this->width  = width;
		this->height = height;
		this->title  = title;
		if(!initGL())
		{
			std::cout << "ERROR: Couldn't initialize window!" << std::endl;
			Quit();
			exit(EXIT_FAILURE);
		}

		title.append(" - SDL2");

		window = SDL_CreateWindow(title.c_str(),x,y,
				width,height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		context = SDL_GL_CreateContext(window);

		glewExperimental = GL_TRUE;
		glewInit();
	}

	void CleanScreen(float r, float g, float b, float a)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(r,g,b,a);
	}

	void SwapBuffers()
	{
		SDL_GL_SwapWindow(window);
	}

	void Delay(uint32_t ms)
	{
		SDL_Delay(ms);
	}

	bool UserWannaQuit()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			return true;
		return false;
	}

	void Quit()
	{
		SDL_GL_DeleteContext(context);
		SDL_Quit();
	}
};

#endif
