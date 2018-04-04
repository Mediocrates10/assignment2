#pragma once

#include "deps\include\SDL\SDL.h"

namespace scene
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		bool init();
		void update();
		void draw(SDL_Surface &surface) const;
		bool shutdown();
		SDL_Surface* Image = NULL;
	protected:
		float rectX;
		float rectY;
	};
}


