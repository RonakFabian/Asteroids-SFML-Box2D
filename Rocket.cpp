#include "Rocket.h"

#include <iostream>

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
	
	this->body->SetLinearDamping(5);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x = -1;

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x = 1;
	else
	

	this->body->ApplyLinearImpulse(velocity,body->GetWorldCenter(),true);
	

}
