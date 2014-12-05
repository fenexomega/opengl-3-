#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <stdint.h>

class Display
{
private:
  unsigned int x,y;
  unsigned int width,height;
  std::string title;
public:

    Display(int x,int y, int width, int height, std::string title)
    {
      this->x 	 = x;
      this->y  	 = y;
      this->width  = width;
      this->height = height;
      this->title  = title;
    }

    virtual void CleanScreen(float r, float g, float b, float a) = 0;

    virtual void SwapBuffers() = 0;

    virtual void Delay(uint32_t ms) = 0;

    virtual bool UserWannaQuit() = 0;

    virtual void Quit() = 0;

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
