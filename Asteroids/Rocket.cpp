#include "Rocket.h"
#include <iostream>


Rocket::Rocket(b2World* world) :Entity(world)
{
	texture = new  sf::Texture;
	this->active = 1;
	this->groupId = 0;
	this->world = world;
}

Rocket::~Rocket()
{
	
}

bool Rocket::Update(sf::RenderWindow* window)
{
	Entity::Update(window);

	body->SetLinearDamping(.01);
	body->SetAngularDamping(1);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		body->ApplyTorque(-100000, true);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		body->ApplyTorque(100000, true);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocityX = body->GetMass() * 1 * sin(body->GetAngle());
		velocityY = body->GetMass() * 1 * -cos(body->GetAngle());
		body->ApplyForceToCenter(b2Vec2(velocityX, velocityY), true);
	}
	
	return true;
}
