#include "stdafx.h"
#include "GameObject.h"
#include "deps\include\SDL\SDL.h"
#include <stdio.h>
#include "InputSystem.h"

namespace scene
{
	GameObject::GameObject()
	{
	}


	GameObject::~GameObject()
	{
	}
	bool GameObject::init()
	{
		printf("GameObject initialized\n");
		bool success = true;

		Image = SDL_LoadBMP("myimage.bmp");
		if (Image == NULL) {
			printf("Unable to load image %s! SDL Error: %s\n", "myimage.bmp", SDL_GetError());
			success = false;
		}
		return success;
	}
	void GameObject::update()
	{
		SDL_Event e;

		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case (SDL_KEYDOWN):
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					printf("UP\n");
					Image->clip_rect.y -= 10;
					break;
				case SDLK_DOWN:
					printf("DOWN\n");
					Image->clip_rect.y += 10;
					break;
				case SDLK_RIGHT:
					printf("RIGHT\n");
					Image->clip_rect.x += 10;
					break;
				case SDLK_LEFT:
					printf("LEFT\n");
					Image->clip_rect.x -= 10;
					break;
				}
			}
		}
	}
	void GameObject::draw(SDL_Surface &surface) const
	{
		SDL_BlitSurface(Image, NULL, &surface, &Image->clip_rect);
	}
	bool GameObject::shutdown()
	{
		return true;
	}
}


