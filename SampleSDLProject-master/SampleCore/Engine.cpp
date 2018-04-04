#include "stdafx.h"
#include "Engine.h"
#include "Scene.h"
#include <iostream>
#include "deps\include\SDL\SDL.h"
#include "InputSystem.h"
#include "GameObject.h"

#include "SystemManager.h"
namespace Core
{

	Engine::Engine(scene::Scene *s) : MainScene(s), isRunning(false)
	{
		managers.push_back(SystemManager::getInstance());
	}

	Engine::~Engine()
	{
	}

	int Engine::init()
	{
		int initResult = 0;


		//Initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

			initResult = ENGINE_INIT_ERROR;
		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

				initResult = ENGINE_INIT_ERROR;
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);

				//Fill the surface blue
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 150, 250));

				//Wait two seconds
				//SDL_Delay(2000);
			}
		}
		//MainScene->setSurface(static_cast<SystemManager*>(managers.at(0))->GetSystem(Core::SystemType::WINDOW));
		MainScene->setSurface(*screenSurface);
		MainScene->init();
		return 0;
	}
	int Engine::run()
	{
		isRunning = true;
		//systemManager
		while (!inputSystem.QuitRequested())
		{
			//update
			update();
			//render
			draw();

		}
		return shutdown();
	}
	void Engine::update()
	{
		inputSystem.update();
		MainScene->update();
		
		//Update the surface
		SDL_UpdateWindowSurface(window);

	}
	void Engine::draw() const
	{
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 150, 250));
		MainScene->draw();
	}
	int Engine::shutdown()
	{
		if (MainScene->shutdown())
		{
			return 1;
		}

		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();
		return 0;
	}
}

