#ifndef BRUGLESCO_MEMORY_CARD_H
#define BRUGLESCO_MEMORY_CARD_H

#include "Expressions.h"

namespace memory {

	class Card
	{
	public:
		explicit Card(unsigned matchNum);

		unsigned getMatch() const;

		CardState checkState() const;

		void flip();

		void match();

		void reset();
	private:
		unsigned matchNum;
		CardState cardState{ CardState::unmatched };
		bool faceUp{ false };
	};

}

#endif // !BRUGLESCO_MEMORY_CARD_H
