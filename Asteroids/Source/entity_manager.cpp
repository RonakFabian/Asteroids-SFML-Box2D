#include "entity_manager.h"

EntityManager::EntityManager()
{
	this->world = new b2World(b2Vec2(0, 0));
}

void EntityManager::Add(std::string name, Entity* entity)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.end())
	{
		name += "0";
		found = this->entities.find(name);
	}
	this->entities.insert(std::make_pair(name, entity));
}

void EntityManager::Add(std::string name, std::string filename, bool dynamic)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.end())
	{
		name += "0";
		found = this->entities.find(name);
	}
	Entity* entity = new Entity(this->world);
	entity->Load(filename, dynamic);
	this->entities.insert(std::make_pair(name, entity));
}

void EntityManager::Add(std::string name, std::string filename, bool dynamic,  float x, float y)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.end())
	{
		name += "0";
		found = this->entities.find(name);
	}
	Entity* entity = new Entity(this->world);
	entity->Load(filename, dynamic,x,y);
	this->entities.insert(std::make_pair(name, entity));
}

void EntityManager::Add(std::string name, std::string filename, bool dynamic, float x, float y, Entity* entity)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.end())
	{
		name += "0";
		found = this->entities.find(name);
	}
	
	entity->Load(filename, dynamic, x, y);
	this->entities.insert(std::make_pair(name, entity));
	
}

void EntityManager::Remove(std::string name)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);

	if (found == this->entities.end())
	{
		return ;
	}
	else
	{
		if(found->second!=nullptr)
		entities.erase(found);
	}
}

Entity* EntityManager::Get(std::string name)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);

	if (found == this->entities.end())
	{
		return NULL;
	}
	else
	{
		return found->second;
	}
}

bool EntityManager::Update(sf::RenderWindow* window)
{
	std::vector<std::string> toRemove;

	this->world->Step(1.0f / 60.0f, 6, 2);

	return true;
}

void EntityManager::Render(sf::RenderWindow* window)
{
	for (auto& iterator : this->entities)
	{
	
		if (iterator.second->canUpdate)
		{
			window->draw(*iterator.second);
			iterator.second->Update(window);
		}
		
	}
}

EntityManager::~EntityManager()
{
	for (auto& iterator : this->entities)
	{
		delete iterator.second;
	}
	this->entities.clear();
	delete this->world;
}