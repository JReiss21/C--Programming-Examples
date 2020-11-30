/*
This is the deck implementation file for the blackjack program assignment
Written by Joseph Reiss U76703774
*/

//include directives
#include "Deck.h"
#include "Card.h"
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>

/*
shuffle deck from deck class
precondition: none
postcondition: shuffles the current deck objects cards
*/
void Deck::shuffle_deck()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);

	std::shuffle(this->deck.begin(), this->deck.end(), e);
}

/*
create new full deck function from deck header file
precondition: none
postcondition: creates a new full UN-SHUFFLED deck of 52 cards and returns the object
*/
Deck create_new_full_deck()
{
	//variables
	std::string suit;
	std::string rank;
	Card new_card;
	std::stringstream ss;
	Deck new_deck;

	for (int i = 0; i < 4; i++)	//looping through each suit and than each card in each suit to assign it right values than add it to a new deck
	{
		if (i == 0)
		{
			suit = "Hearts";
			new_card.set_suit(suit);
			for (int j = 1; j <= 13; j++)
			{
				new_card.set_value(j);
				if (j > 10 || j == 1)
				{
					if (j == 11)
					{
						rank = "Jack";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					else if (j == 12)
					{
						rank = "Queen";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					else if (j == 13)
					{
						rank = "King";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					else if (j == 1)
					{
						rank = "Ace";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
				}
				else
				{
					ss.clear();
					ss << j;
					ss >> rank;
					new_card.set_rank(rank);
					new_deck.deck.push_back(new_card);
				}
			}
		}
		else if (i == 1)
		{
			suit = "Spades";
			new_card.set_suit(suit);
			for (int j = 1; j <= 13; j++)
			{
				new_card.set_value(j);
				if (j > 10 || j == 1)
				{
					if (j == 11)
					{
						rank = "Jack";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					if (j == 12)
					{
						rank = "Queen";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					if (j == 13)
					{
						rank = "King";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					if (j == 1)
					{
						rank = "Ace";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
				}
				else
				{
					ss.clear();
					ss << j;
					ss >> rank;
					new_card.set_rank(rank);
					new_deck.deck.push_back(new_card);
				}
			}
		}
		else if (i == 2)
		{
			suit = "Clubs";
			new_card.set_suit(suit);
			for (int j = 1; j <= 13; j++)
			{
				new_card.set_value(j);
				if (j > 10 || j == 1)
				{
					if (j == 11)
					{
						rank = "Jack";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					if (j == 12)
					{
						rank = "Queen";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					if (j == 13)
					{
						rank = "King";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					if (j == 1)
					{
						rank = "Ace";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
				}
				else
				{
					ss.clear();
					ss << j;
					ss >> rank;
					new_card.set_rank(rank);
					new_deck.deck.push_back(new_card);
				}
			}
		}
		else if (i == 3)
		{
			suit = "Diamonds";
			new_card.set_suit(suit);
			for (int j = 1; j <= 13; j++)
			{
				new_card.set_value(j);
				if (j > 10 || j == 1)
				{
					if (j == 11)
					{
						rank = "Jack";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					if (j == 12)
					{
						rank = "Queen";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					if (j == 13)
					{
						rank = "King";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
					if (j == 1)
					{
						rank = "Ace";
						new_card.set_rank(rank);
						new_deck.deck.push_back(new_card);
					}
				}
				else
				{
					ss.clear();
					ss << j;
					ss >> rank;
					new_card.set_rank(rank);
					new_deck.deck.push_back(new_card);
				}
			}
		}
	}
	return new_deck;
}