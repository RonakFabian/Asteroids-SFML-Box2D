#pragma once
#include "GameObject.h"
class Rocket :  public GameObject
{
public:
	Rocket(b2World* world, bool dynamic);
	void Update(sf::RenderWindow* window) override;
private:
	void HandleRocketMovement();
};

