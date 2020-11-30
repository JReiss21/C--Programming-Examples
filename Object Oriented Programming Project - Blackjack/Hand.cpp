/*
This is the hand implementation file for the blackjack program assignment
Written by Joseph Reiss U76703774
*/

//include directives 
#include "Hand.h"
#include <vector>
#include <iostream>


//constructor for hand class
Hand::Hand(int points)
{
	this->points = points;
}

/*
set points from the hand class
precondition: passed an integer value to set as the points value
postcondition: sets the current hand object's point value as passed integer
*/
void Hand::set_points(int points)
{
	this->points = points;
}

/*
calculate and set points from hand class
precondition: none
postcondition: calculate the points for the current hand object and than sets it to that value
*/
void Hand::calculate_and_set_points()
{
	int total_points = 0;
	for (Card c : hand)
	{
		total_points += c.get_value();
	}

	this->set_points(total_points);
}

/*
operator += function from the hand class
precondition: passed the hand object and card object to user for the function
postcondition: adds the passed card object to the hand object and resets the points for the hand
*/
void operator += (Hand& hand, const Card& card)
{
	hand.hand.push_back(card);
	hand.calculate_and_set_points();
}