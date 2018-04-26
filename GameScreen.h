#ifndef BRUGLESCO_MEMORY_GAMESCREEN_H
#define BRUGLESCO_MEMORY_GAMESCREEN_H

#include "Expressions.h"
#include "HUDisplay.h"
#include "InputHandler.h"

#include <SFML\Graphics.hpp>

class GameScreen
{
public:
	GameScreen(InputHandler& inputHandler);

	void input(sf::Vector2f mousePos);

	void draw(sf::RenderWindow& window);
private:
	InputHandler& m_inputHandler;
	sf::Texture gameBackground;
	sf::Sprite backgroundSprite{ gameBackground, sf::IntRect(0, 0, window_width, window_height) };
	sf::RectangleShape pause{ sf::Vector2f(game_button_width, game_button_height) };
	sf::RectangleShape reset{ sf::Vector2f(game_button_width, game_button_height) };
	HUDisplay hud;
};

#endif // !BRUGLESCO_MEMORY_GAMESCREEN_H
