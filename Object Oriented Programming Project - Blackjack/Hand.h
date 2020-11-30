/*
This is the hand header file for the blackjack program assignment
Written by Joseph Reiss U76703774
*/

#ifndef HAND_H
#define HAND_H

//include directives
#include "Card.h"
#include <string>
#include <vector>

//hand class
class Hand {
public:
	//data members
	std::vector<Card> hand;
	int points;

	//constructor
	Hand(int points = 0);

	//member functions
	int get_points() const { return points; }
	void set_points(int points);

	void calculate_and_set_points();

	friend void operator += (Hand&, const Card&);
};

#endif HAND_H