#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glew.h>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Display
{
private:
	unsigned int x,y;
	unsigned int width,height;
	std::string title;
	sf::Window* window;
public:
	static bool initGL()
	{
		bool flag = true;


		return flag;


	}

	Display(int x,int y, int width, int height, std::string title)
	{
		this->x 	 = x;
		this->y  	 = y;
		this->width  = width;
		this->height = height;
		this->title  = title;
		sf::ContextSettings settings;	
		settings.depthBits = 24;
		settings.stencilBits = 8;
		settings.antialiasingLevel = 2;
		settings.majorVersion = 3;
		settings.minorVersion = 1;
		window = new sf::Window(sf::VideoMode(width,height),title,sf::Style::Close,settings);


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
		window->display();
	}


	bool UserWannaQuit()
	{
		sf::Event event;
		window->pollEvent(event);
		if(event.type == sf::Event::Closed )
			return true;
		return false;
	}
};

#endif
