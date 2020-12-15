#include "GameObject.h"

#include <iostream>
#include <memory>


GameObject::GameObject(b2World* world,bool dynamic)
{
	this->world = world;
	circle = new sf::CircleShape(10);
	circle->setPosition(0, 0);
	circle->setFillColor(sf::Color::Red);

	this->bodyDef = new b2BodyDef();
	if (dynamic)
	{
		this->bodyDef->type = b2_dynamicBody;
	}
	else
	{
		this->bodyDef->type = b2_staticBody;
	}
	this->bodyDef->position.Set(circle->getPosition().x, circle->getPosition().y);
	this->body = this->world->CreateBody(this->bodyDef);

	this->shape = new b2PolygonShape();
	this->shape->SetAsBox(this->circle->getRadius() * 0.5f - b2_polygonRadius, this->circle->getRadius() * 0.5f - b2_polygonRadius);

	this->fixtureDef = new b2FixtureDef();
	this->fixtureDef->shape = this->shape;

	if (dynamic)
	{
		this->fixtureDef->density = 1.0f;
		this->fixtureDef->friction = 0.3f;
		this->body->CreateFixture(this->fixtureDef);
	}
	else
	{
		this->body->CreateFixture(this->shape, 0);
	}

}

GameObject::~GameObject()
{
	delete this->circle;
}

void GameObject::Update(sf::RenderWindow* window)
{
	b2Vec2 pos = this->body->GetPosition();
	float rot = this->body->GetAngle();
	circle->setPosition(pos.x, -pos.y);
	circle->setRotation(rot);
}
