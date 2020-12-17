#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>


class GameObject:public sf::Sprite
{

public:
	const   double  DEGTORAD = 0.01745329252;
	GameObject(b2World* world, bool dynamic);
	~GameObject();

	sf::RectangleShape* circle;
		b2Vec2 velocity;
	b2Body* body;
	float angle;
	virtual void Update(sf::RenderWindow* window);
	void SetTexture( std::string file);
	
private:
	b2World* world;
	b2BodyDef* bodyDef;
	b2PolygonShape* shape;
	b2FixtureDef* fixtureDef;
	sf::Texture* texture;
};
