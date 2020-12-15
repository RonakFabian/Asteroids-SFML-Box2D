#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "Scene.h"


int main()
{
	auto my_scene= new Scene;

	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
	

	my_scene->SetWindow(&window);
	

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		


		window.clear();
		my_scene->Render(&window);
		window.display();
	}

	return 0;
}
