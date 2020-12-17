#include "Rocket.h"
#include <iostream>
#include <cmath>

Rocket::Rocket(b2World* world, bool dynamic) :GameObject(world, dynamic)
{
	this->circle->setFillColor(sf::Color::Blue);
	this->body->SetLinearDamping(5);
	 
}



void Rocket::Update(sf::RenderWindow* window)
{
	GameObject::Update(window);
	HandleRocketMovement();
}

void Rocket::HandleRocketMovement()
{
	//
	// this->body->SetLinearDamping(5);
	//
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -1;
		angle += velocity.x;
		
	}

	
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = 1;
	}
	else
	{
		velocity.x = 0;
	}
	
	
	
	this->body->SetAngularVelocity(velocity.x*5);
	
	float velocity =1; // Your desired velocity of the car.
	float angle = body->GetAngle(); // Body angle in radians.

	float velX = cos(angle) * velocity; // X-component.
	float velY = sin(angle) * velocity; // Y-component.

	body->SetLinearVelocity(b2Vec2(velX, velY));
	
	
	
	

}
