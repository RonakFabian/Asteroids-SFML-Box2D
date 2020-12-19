#pragma once

#include <unordered_map>
#include <Box2D/Box2D.h>
#include "entity.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void Add(std::string name, Entity* entity);
	void Add(std::string name, std::string filename, bool dynamic);
	void Add(std::string name, std::string filename, bool dynamic, float x, float y);
	void Add(std::string name, std::string filename, bool dynamic, float x, float y, Entity* entity);
	void Remove(std::string name);


	Entity* Get(std::string name);

	bool Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);


	b2World* world;
private:
	std::unordered_map<std::string, Entity*> entities;


};