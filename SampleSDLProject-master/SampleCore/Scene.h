#pragma once
#include <vector>
#include "deps\include\SDL\SDL.h"
namespace scene
{
	class Scene
	{
	protected:
		std::vector<class GameObject*> gameObject;
		SDL_Surface* sceneSurface = NULL;
	public:
		Scene();
		virtual ~Scene();

		virtual bool init();
		virtual void update();
		virtual void draw() const;
		virtual bool shutdown();

		void setSurface(SDL_Surface &surface);
	};
}


