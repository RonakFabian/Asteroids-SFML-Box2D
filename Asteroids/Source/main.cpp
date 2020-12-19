
#include "game_state.h"
#include "test_state.h"

game_state coreState;
bool quitGame = false;
 

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT,32), "Role Call");
	srand(time(NULL));
	coreState.SetWindow(&window);
	coreState.SetState(new test_state());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		coreState.Update();
		coreState.Render();

		window.display();

		if (quitGame)
		{
			window.close();
		}

	}

	return 0;
}
