#include "Scene.h"
#include <iostream>



Scene::Scene()
{
	world = new b2World(b2Vec2(0, 0));
	auto go = new GameObject(world, true);
	Rocket* rocket = new  Rocket(world,true);

	//Add("One", go);
	Add("Rocket", rocket);



}

void Scene::Add(std::string name, GameObject* go)
{
	hierarchy.insert(std::make_pair(name, go));
}


void Scene::Render(sf::RenderWindow* render_window)
{
	this->world->Step(1.0f / 60.0f, 2, 1);

	for (auto& n : hierarchy)
	{
		render_window->draw(*(n.second)->circle);
		n.second->Update(window);
	}

}


bool Scene::Update(sf::RenderWindow* render_window)
{

	return true;
}

void Scene::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
}

GameObject* Scene::GetGameObject(std::string name)
{
	std::unordered_map<std::string, GameObject*>::const_iterator item = hierarchy.find(name);
	if (item == hierarchy.end())
	{

		return nullptr;
	}
	else
		return  item->second;
}

Scene::~Scene()
{



	delete window;
}


