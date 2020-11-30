/*
This is the card implementation file for the blackjack program assignment
Written by Joseph Reiss U76703774
*/

//include directives
#include "Card.h"
#include <iostream>

//constructor
Card::Card(std::string suit, std::string rank, int value)
{
	this->suit = suit;
	this->rank = rank;
	this->value = value;
}

/*
set suit from card class
precondition: passed a string value to set as the suit for the card
postcondition: sets the passed string value as the current cards suit value
*/
void Card::set_suit(std::string suit)
{
	this->suit = suit;
}

/*
set rank from card class
precondition: passed a string value to set as the rank for the card
postcondition: sets the passed string value as the current cards rank value
*/
void Card::set_rank(std::string rank)
{
	this->rank = rank;
}

/*
set value from card class
precondition: passed an integer value to assign as a value to the card
postcondition: sets the cards value to help with comparison in adding points for blackjack
*/
void Card::set_value(int value)
{
	this->value = value;
}

/*
operator << function from the card class
precondition: passed an output stream object and a card object to user for function
postcondition: returns the output stream object outputting the description of the card "rank of suit"
*/
std::ostream& operator << (std::ostream& out, const Card& card)
{
	out << card.get_rank() << " of " << card.get_suit() << std::endl;
	return out;
}