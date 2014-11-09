#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>

class Display
{
private:
	unsigned int x,y;
	unsigned int width,height;
	std::string title;
	SDL_Window *window;
public:
	static bool initSDLandGL()
	{
		bool flag = true;
		if(SDL_Init(SDL_INIT_VIDEO) != 0)
			flag = false;
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
		
		return flag;
	}

	Display(int x,int y, int width, int height, std::string title)
	{
		this->x 	 = x;
		this->y  	 = y;
		this->width  = width;
		this->height = height;
		this->title  = title;
		window = SDL_CreateWindow(title.c_str(),x,y,
				width,height,
				SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		SDL_GLContext context = SDL_GL_CreateContext(window);

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

	bool UserWannaQuit()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			return true;
		return false;
	}
};
