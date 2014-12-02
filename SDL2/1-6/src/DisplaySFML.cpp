#include "DisplaySFML.h"



bool DisplaySFML::initGL()
{
    bool flag = true;


    return flag;


}

DisplaySFML::DisplaySFML(int x, int y, int width, int height, std::string title)
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

    glViewport(0,0,width,height);

}

void DisplaySFML::CleanScreen(float r, float g, float b, float a)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(r,g,b,a);
}

void DisplaySFML::SwapBuffers()
{
    window->display();
}

void DisplaySFML::Delay(uint32_t ms)
{
    sf::sleep(sf::milliseconds(ms));
}

void DisplaySFML::Quit()
{
    window->close();
}

bool DisplaySFML::UserWannaQuit()
{
    sf::Event event;
    window->pollEvent(event);
    if(event.type == sf::Event::Closed )
        return true;
    return false;
}
