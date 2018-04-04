#include "stdafx.h"
#include "InputSystem.h"
#include "deps\include\SDL\SDL.h"
#include "GameObject.h"
#include "Scene.h"
namespace Core
{
    InputSystem::InputSystem() : System(SystemType::INPUT), requestedQuit(false)
    {
    }
    
    
    InputSystem::~InputSystem()
    {
    }

	float InputSystem::setRectX(float x) {
		x += 1;
		return x;
	}
	float InputSystem::setRectY(float y) {
		y += 1;
		return y;
	}

	void InputSystem::update()
	{
		/*SDL_Event e;

		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case (SDL_KEYDOWN):
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					printf("UP\n");
					e_upPressed = true;
					break;
				case SDLK_DOWN:
					printf("DOWN\n");
					e_downPressed = true;
					break;
				case SDLK_RIGHT:
					printf("RIGHT\n");
					e_rightPressed = true;
					break;
				case SDLK_LEFT:
					printf("LEFT\n");
					e_leftPressed = true;
					break;
				case SDLK_ESCAPE:
					requestedQuit = true;
					break;
				}
				//printf("You pressed something");
				break;
			case (SDL_KEYUP):
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					e_upPressed = false;
					printf("Up released\n");
					break;
				case SDLK_DOWN:
					e_downPressed = false;
					printf("Down released\n");
					break;
				case SDLK_RIGHT:
					e_rightPressed = false;
					printf("Right released\n");
					break;
				case SDLK_LEFT:
					e_leftPressed = false;
					printf("Left released\n");
					break;
				}
			default:
				break;
			}

		}*/
	}

}
