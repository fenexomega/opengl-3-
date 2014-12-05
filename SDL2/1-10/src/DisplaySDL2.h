#ifndef DISPLAYSDL2_H
#define DISPLAYSDL2_H



#include <GL/glew.h>

#include <SDL2/SDL.h>
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
    bool initGL();
public:

    DisplaySDL2(int x,int y, int width, int height, std::string title);

    void CleanScreen(float r, float g, float b, float a);

    void SwapBuffers();

    void Delay(uint32_t ms);

    bool UserWannaQuit();

    void Quit();

	//Getters and Setters
	const float getRatio()
	{
		return (float) width/height; 
	}

	const int getWidth()
	{
		return width;
	}

	const int getHeight()
	{
		return height;
	}

};

#endif
