#include "Memory.h"

Memory::Memory()
{
	window.setFramerateLimit(60);
}

void Memory::run()
{
	while (window.isOpen())
	{
		input();
		update();
		draw();
	}
}

void Memory::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		window.close();
	}

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			sf::Vector2f mousePos = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
			if (!playing)
			{
				mainMenu.input(mousePos);
			}
			else
			{
				gameScreen.input(mousePos);
			}
		}
	}
}

void Memory::update()
{
	if (!playing)
	{
		deckSize = inputHandler.readSize();
		if (inputHandler.readPlay())
		{
			// set board
			paused = false;
			playing = true;
			inputHandler.switchOff();
		}
	}
	else
	{
		if (inputHandler.readPause())
		{
			paused = !paused;
			inputHandler.switchOff();
		}
		if (inputHandler.readReset() && !paused)
		{
			// reset board and stats
			inputHandler.switchOff();
		}
	}
	// call necessary update functions
}

void Memory::draw()
{
	window.clear();

	if (!playing)
	{
		mainMenu.draw(window);
	}
	else
	{
		gameScreen.draw(window);
	}

	window.display();
}
