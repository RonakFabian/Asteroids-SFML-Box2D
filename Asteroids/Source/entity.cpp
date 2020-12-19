#include "entity.h"


Entity::Entity(b2World* world)
{
	this->texture = new sf::Texture();
	this->active = 1;
	this->groupId = 0;
	this->canUpdate = true;
	this->world = world;
}

void Entity::Load(std::string filename, bool dynamic)
{
	this->texture->loadFromFile("Graphics/sprites/" + filename);
	this->setTexture(*this->texture);

	this->bodyDef = new b2BodyDef();
	if (dynamic)
	{
		this->bodyDef->type = b2_dynamicBody;
	}
	else
	{
		this->bodyDef->type = b2_staticBody;
	}
	this->bodyDef->position.Set(this->getPosition().x, this->getPosition().y);
	this->body = this->world->CreateBody(this->bodyDef);

	this->shape = new b2PolygonShape();
	
		this->shape->SetAsBox(this->texture->getSize().x * 0.5f, this->texture->getSize().y * 0.5f);
	


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

void Entity::Load(std::string filename, bool dynamic,  float x, float y)
{

	this->texture->loadFromFile("Graphics/sprites/" + filename);
	this->setTexture(*this->texture);

	this->bodyDef = new b2BodyDef();
	if (dynamic)
	{
		this->bodyDef->type = b2_dynamicBody;
	}
	else
	{
		this->bodyDef->type = b2_staticBody;
	}

	this->bodyDef->position.Set(this->getOrigin().x, getOrigin().y  );
	
	this->body = this->world->CreateBody(this->bodyDef);

	this->shape = new b2PolygonShape();

		
	this->shape->SetAsBox(x* 0.5f, y*0.5f);
	


	this->fixtureDef = new b2FixtureDef();
	this->fixtureDef->shape = this->shape;

	if (dynamic)
	{
		this->fixtureDef->density = .50f;
		this->fixtureDef->friction = 0.f;
		this->body->CreateFixture(this->fixtureDef);
	}
	else
	{
		this->body->CreateFixture(this->shape, 0);
	}
	world ->Step(1.f / 60, 6, 2);
	this->setOrigin(texture->getSize().x/2, texture->getSize().y/2);
	
}

void Entity::LoadWithPixelSize( float x, float y)
{
	
	this->shape->SetAsBox(x * 0.5f - b2_polygonRadius, y * 0.5f - b2_polygonRadius);


	
}

bool Entity::Update(sf::RenderWindow* window)
{
	
		//window->draw(*this);

		float x = (body->GetPosition().x);
		float y = (body->GetPosition().y);



		WrapAroundScreen(x, y);

		body->SetTransform(b2Vec2(x, y), body->GetAngle());
		this->setPosition(x, y);
		this->setRotation(body->GetAngle() * (180 / b2_pi));
		
	
	
	return true;
}
void Entity::Collision(Entity* entity)
{
}

bool Entity::CheckCollision(Entity* entity)
{
	//entity->canUpdate = false;
	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

int Entity::GroupID()
{
	return this->groupId;
}

int Entity::Active()
{
	return this->active;
}

void Entity::Destroy(b2World* world)
{
	
}

b2Body* Entity::GetBody() const
{
	return this->body;
}

void Entity::WrapAroundScreen( float& x,  float& y)
{
	if (x < 0)
		x = SCREEN_WIDTH;


	if (x > SCREEN_WIDTH)
		x = 0;
	
	if (y < 0)
		y = SCREEN_HEIGHT;
	
	if (y > SCREEN_HEIGHT)
		y = 0;
}

Entity::~Entity()
{
	delete this->texture;
	delete this->shape;
	delete this->world;
	delete this->fixtureDef;
	
}
