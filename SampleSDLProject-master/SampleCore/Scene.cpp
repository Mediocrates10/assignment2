#include "stdafx.h"
#include "Scene.h"
#include "deps\include\SDL\SDL.h"

namespace scene
{
	Scene::Scene()
	{
	}


	Scene::~Scene()
	{
	}

	bool Scene::init()
	{
		return true;
	}
	void Scene::update()
	{
	}
	void Scene::draw() const
	{

	}
	bool Scene::shutdown()
	{
		return true;
	}

	void Scene::setSurface(SDL_Surface &surface) {
		sceneSurface = &surface;
	}
}
