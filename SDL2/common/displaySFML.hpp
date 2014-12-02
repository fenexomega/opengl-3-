#ifndef DISPLAYSFML_H
#define DISPLAYSFML_H


#ifdef CLANG_COMPLETE_ONLY
#include <GL/gl.h>
#include <GL/glext.h>
#else
#include <GL/glew.h>
#endif

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class DisplaySFML
{
private:
	unsigned int x,y;
	unsigned int width,height;
	std::string title;
	sf::Window* window;
	bool initGL()
	{
		bool flag = true;


		return flag;


	}

public:
	DisplaySFML(int x,int y, int width, int height, std::string title)
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
		title.append(" - SFML");
		window = new sf::Window(sf::VideoMode(width,height),title,sf::Style::Close,settings);

		sf::Vector2i vetor(x,y);
		window->setPosition(vetor);

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

	void Delay(uint32_t ms)
	{
		sf::sleep(sf::milliseconds(ms));
	}

	void Quit()
	{
		window->close();
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
