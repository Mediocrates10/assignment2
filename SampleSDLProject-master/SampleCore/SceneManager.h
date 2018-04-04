#pragma once
#include <vector>
class SceneManager
{
	protected:
		std::vector<class Scene*> scenes;
	public:
	SceneManager();
	~SceneManager();
};

