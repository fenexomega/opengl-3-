#ifndef DISPLAYSFML_H
#define DISPLAYSFML_H

#include <GL/glew.h>

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
    bool initGL();

public:
    DisplaySFML(int x,int y, int width, int height, std::string title);

    void CleanScreen(float r, float g, float b, float a);

    void SwapBuffers();

    void Delay(uint32_t ms);

    void Quit();

    bool UserWannaQuit();
};

#endif
