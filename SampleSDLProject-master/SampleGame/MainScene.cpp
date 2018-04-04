#include "stdafx.h"
#include "MainScene.h"
#include <Scene.h>
#include <GameObject.h>
#include <SystemManager.h>
#include <InputSystem.h>
#include <iostream>
#include <Window.h>


MainScene::MainScene()
{
	using namespace scene;
	gameObject.push_back(new GameObject);
}

MainScene::~MainScene()
{
}
bool MainScene::init()
{
	using namespace scene;
	for (GameObject* g:gameObject)
	{
		g->init();
	}
	std::cout << "Scene is initialized" << std::endl;
	return true;
 }
void MainScene::update()
{
	using namespace Core;
	SystemManager* sm = Core::SystemManager::getInstance();
	//SystemManager* sm = SystemManager::getInstance();

	System* systemDontKnowYet = sm->GetSystem(Core::SystemType::INPUT);
	//InputSystem* inputSystem = dynamic_cast<Core::InputSystem*>(sm->GetSystem(Core);

	InputSystem* inputSystem = dynamic_cast<InputSystem*>(systemDontKnowYet);
	//Window* window = dynamic_cast<Core::Window*>(sm->GetSystem<Core::Window>());

	/*if (inputSystem->IsLeftPressed) 
		printf("works");*/
		
		

	using namespace scene;
	for (GameObject* g : gameObject)
	{
		g->update();
	}
	
	//std::cout << "Scene is updated" << std::endl;
 }
void MainScene::draw() const
{
	using namespace scene;
	for (GameObject* g : gameObject)
	{
		g->draw(*sceneSurface);
	}
	//std::cout << "Scene is drawn" << std::endl;
 }
bool MainScene::shutdown()
{
	using namespace scene;
	for (GameObject* g : gameObject)
	{
		g->shutdown();
	}
	return true;
}

