#pragma once
#include "Source/entity.h"

class Rocket : public Entity
{
public:
	Rocket(b2World* world);

	virtual ~Rocket() override;
	bool Update(sf::RenderWindow* window) override;
private:
	float velocityX;
	float velocityY;
};

