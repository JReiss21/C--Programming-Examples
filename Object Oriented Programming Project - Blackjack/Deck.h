/*
This is the deck header file for the blackjack program assignment
Written by Joseph Reiss U76703774
*/

#ifndef DECK_H
#define DECK_H

//include directives
#include "Card.h"
#include <string>
#include <vector>
#include <sstream>

//deck class
class Deck {
public:
	//data members
	std::vector<Card> deck;

	//constructor
	Deck() {};

	//member functions
	void shuffle_deck();
};

Deck create_new_full_deck();

#endif DECK_H