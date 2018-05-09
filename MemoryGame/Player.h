#ifndef BRUGLESCO_MEMORY_PLAYER_H
#define BRUGLESCO_MEMORY_PLAYER_H

#include "Expressions.h"

#include <SFML\Graphics.hpp>

class Player
{
public:
	Player(unsigned player);

	void scorePoint();

	unsigned getScore() const;

	unsigned getTurn() const;
private:
	unsigned score{ 0 };
	unsigned turn;
};

#endif // !BRUGLESCO_MEMORY_PLAYER_H
