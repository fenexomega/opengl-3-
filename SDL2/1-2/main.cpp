#include "../common/display.h"
#include <iostream>
#include <glm/glm.hpp>

int main()
{
	Display::initSDLandGL();
	Display display(0,0,1024,764,"Daora a vida");

	while(!display.UserWannaQuit())
	{
		display.CleanScreen(0,0,0,1);

		display.SwapBuffers();
	}


	return 0;
}
