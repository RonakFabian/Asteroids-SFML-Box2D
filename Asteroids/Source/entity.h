#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

const  int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class Entity : public sf::Sprite
{
	
public:
	sf::Vector2f velocity;

	Entity(b2World* world);
	virtual ~Entity();

	virtual void Load(std::string filename, bool dynamic);
	virtual void Load(std::string filename, bool dynamic, float x, float y);
	virtual void LoadWithPixelSize(float x, float y);

	virtual bool Update(sf::RenderWindow* window);

	bool CheckCollision(Entity* entity);

	virtual void Collision(Entity* entity);

	int GroupID();
	int Active();
	void Destroy(b2World* world);

	b2Body* GetBody() const;

	
	bool canUpdate;
protected:

	int active;
	int groupId;
	b2World* world;
	b2PolygonShape* shape;
	b2FixtureDef* fixtureDef;
	sf::Texture* texture;
	b2Body* body;
	b2BodyDef* bodyDef;

private:
	void WrapAroundScreen(float& x, float& y);
};

