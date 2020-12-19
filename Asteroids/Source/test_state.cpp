#include "test_state.h"

#include <ostream>

#include "../Rocket.h"
#include "../ObjectPool.h"



bool gameOver = false;

void test_state::Initialize(sf::RenderWindow* window)
{

	auto screen = sf::VideoMode::getDesktopMode();


	manager = new EntityManager();
	const auto rocket = new Rocket(manager->world);
	//const auto asteroid = new Entity(manager->world);
	//const auto bullet = new Entity(manager->world);


	this->manager->Add("Rocket", "Rocket.png", true, 32, 60, rocket);
	this->manager->Get("Rocket")->GetBody()->SetTransform(b2Vec2(1080 / 2, 720 / 2), 0);
	this->manager->Get("Rocket")->scale(sf::Vector2f(1, 1));

	// this->manager->Add("Asteroid", "Asteroid.png", true, 100, 95, asteroid);
	// this->manager->Get("Asteroid")->body->SetTransform(b2Vec2(1080 , 720 / 2), 0);s

	// this->manager->Add("Bullet", "Bullet.png", true, 2, 2, bullet);
	// this->manager->Get("Bullet")->body->SetTransform(b2Vec2(1080, 480 ), 0);
	//this->manager->Get("Asteroid")->scale(sf::Vector2f(1, 1));
	SpawnRate = 2 * 30;
	Begin();
}




void test_state::Update(sf::RenderWindow* window)
{

	if (!this->manager->Update(window))
	{
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		quitGame = true;
	}

	timer += 0.03f;
	if (timer >= SpawnRate)
	{
		timer = 0;
		SpawnProjectiles();
	}
	
	for (int j = 0; j < 10; j++)
	{
	
		if (this->manager->Get("Rocket")->CheckCollision(manager->Get("Asteroid"+std::to_string(j))))
		{
			std::cout << "Hit" << "Asteroid" + std::to_string(j) << std::endl;
			//manager->Get(("Asteroid" + std::to_string(j)))->canUpdate = false;
		}
	}
	

}

void test_state::Render(sf::RenderWindow* window)
{
	this->manager->Render(window);
}
void test_state::Destroy(sf::RenderWindow* window)
{
	delete this->manager;
}

void test_state::Begin()
{
	for (int j = 0; j < 10; j++)
	{
		const auto asteroid = new Entity(manager->world);
		this->manager->Add("Asteroid" + std::to_string(j), "Asteroid.png", true, 100, 95, asteroid);
		this->manager->Get("Asteroid" + std::to_string(j))->GetBody()->SetTransform(b2Vec2((rand() % 1280), (rand() % 720)), 0);

	}



}

void test_state::SpawnProjectiles()
{
	i++;



}
