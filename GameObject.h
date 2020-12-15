#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>


class GameObject 
{
	
public:
	
	GameObject(b2World* world,bool dynamic);
	~GameObject();
	
	sf::CircleShape* circle;
	b2Vec2 velocity;
	b2Body* body;
	virtual void Update(sf::RenderWindow* window);
private:
	b2World* world;
	b2BodyDef* bodyDef;
	b2PolygonShape* shape;
	b2FixtureDef* fixtureDef;

};
