#pragma once

#include <unordered_map>


#include "GameObject.h"
#include "Rocket.h"
#include <Box2D/Box2D.h>

class Scene
{
public:
	Scene();

	void Add(std::string name, GameObject* go);
	void Add(std::string name, std::string filename, bool dynamic);
	

	bool Update(sf::RenderWindow* window);

	
	void Render(sf::RenderWindow* window);
	void SetWindow(sf::RenderWindow* window);

	std::unordered_map<std::string, GameObject*> hierarchy;
	
	inline b2World* GetWorld() const { return  world; }
	 GameObject* GetGameObject(std::string name);
	
	~Scene();
	
private:
	
	sf::RenderWindow* window;
	b2World* world;

};

