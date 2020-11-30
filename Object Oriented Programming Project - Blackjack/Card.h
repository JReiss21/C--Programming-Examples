/*
This is the card header file for the blackjack program assignment
Written by Joseph Reiss U76703774
*/

#ifndef CARD_H
#define CARD_H

//include directives
#include <string>

//card class
class Card {
public:
	//data members
	std::string suit;
	std::string rank;
	int value;

	//constructor
	Card(std::string suit = "", std::string rank = "", int value = 0);

	//member functions
	std::string get_suit() const { return suit; }
	std::string get_rank() const { return rank; }
	int get_value() const { return value; }

	void set_suit(std::string);
	void set_rank(std::string);
	void set_value(int);

	friend std::ostream& operator << (std::ostream&, const Card&);
};

#endif CARD_H