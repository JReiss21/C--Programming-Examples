/*
This program is the solution to the black jack assignment
Written by Joseph Reiss U76703774
*/

//include directives
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <iostream>
#include <limits>

//namepsace
using namespace std;

//main functions
int main()
{
	//beginning message
	cout << "\nBlackjack\n\n";

	while (true)
	{
		//creating new full unshuffled deck than shuffling it
		Deck deck = create_new_full_deck();
		deck.shuffle_deck();

		//variables
		Hand dealer_hand;
		Hand player_hand;

		//dealing dealers first card and outputting
		dealer_hand += deck.deck.back();
		deck.deck.pop_back();

		cout << "DEALER'S SHOWN CARD:" << endl;
		cout << dealer_hand.hand.front();

		//dealing players first two cards and outputting
		player_hand += deck.deck.back();
		deck.deck.pop_back();
		player_hand += deck.deck.back();
		deck.deck.pop_back();

		cout << endl << "YOUR CARDS:" << endl;
		for (Card c : player_hand.hand)
		{
			cout << c;
		}

		//variables
		char hit_or_stand = ' ';
		//initial ask to hit or stand for player
		while (true)
		{
			cout << endl << "Hit or stand? (h/s)?: ";
			cin >> hit_or_stand;
			if (!cin.good())
			{
				cout << endl << "Invalid input. Not a character. Try again." << endl;
				cin.ignore();
				cin.clear(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			if (tolower(hit_or_stand) != 'h' && tolower(hit_or_stand) != 's')
			{
				cout << endl << "Invalid character entered. Try again." << endl;
				continue;
			}
			break;
		}

		//loop to continue while player wants to hit or until busts
		while (hit_or_stand == 'h')
		{
			player_hand += deck.deck.back();
			deck.deck.pop_back();
			
			cout << endl << "YOUR CARDS:" << endl;
			for (Card c : player_hand.hand)
			{
				cout << c;
			}

			if (player_hand.get_points() > 21)
			{
				cout << endl << "Your points: " << player_hand.get_points() << endl;
				cout << "You went over 21 points. Dealer wins." << endl;
				cout << "Game over!" << endl;
				break;
			}

			while (true)
			{
				cout << endl << "Hit or stand? (h/s)?: ";
				cin >> hit_or_stand;
				if (!cin.good())
				{
					cout << endl << "Invalid input. Not a character. Try again." << endl;
					cin.ignore();
					cin.clear(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				if (tolower(hit_or_stand) != 'h' && tolower(hit_or_stand) != 's')
				{
					cout << endl << "Invalid character entered. Try again." << endl;
					continue;
				}
				break;
			}
		}
		
		if (player_hand.get_points() <= 21)
		{
			while (dealer_hand.get_points() < 17)
			{
				dealer_hand += deck.deck.back();
				deck.deck.pop_back();
			}

			//displaying dealers cards
			cout << endl << "DEALER'S CARDS:" << endl;
			for (Card c : dealer_hand.hand)
			{
				cout << c;
			}
			cout << endl;

			if (dealer_hand.get_points() > 21)
			{
				cout << "YOUR POINTS: " << player_hand.get_points() << endl;
				cout << "DEALER'S POINTS: " << dealer_hand.get_points() << endl;
				cout << endl << "The dealer busted. You win!" << endl;
			}
			else if(dealer_hand.get_points() > player_hand.get_points())
			{
				cout << "YOUR POINTS: " << player_hand.get_points() << endl;
				cout << "DEALER'S POINTS: " << dealer_hand.get_points() << endl;
				cout << endl << "The Dealer Wins! Good luck next time." << endl;
			}
			else if (dealer_hand.get_points() < player_hand.get_points())
			{
				cout << "YOUR POINTS: " << player_hand.get_points() << endl;
				cout << "DEALER'S POINTS: " << dealer_hand.get_points() << endl;
				cout << endl << "The Player Wins! Congratulations!" << endl;
			}
			else if (dealer_hand.get_points() == player_hand.get_points())
			{
				cout << "YOUR POINTS: " << player_hand.get_points() << endl;
				cout << "DEALER'S POINTS: " << dealer_hand.get_points() << endl;
				cout << endl << "It's a Draw! Nobody wins." << endl;
			}
		}

		//loop to ask user to continue until a valid character is entered
		char play_again = ' ';
		while (true)
		{
			cout << endl << "Play again? (y/n)?: ";
			cin >> play_again;
			cout << endl;
			if (!cin.good())
			{
				cout << endl << "Invalid input. Not a character. Try again." << endl;
				cin.ignore();
				cin.clear(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			if (tolower(play_again) != 'y' && tolower(play_again) != 'n')
			{
				cout << endl << "Invalid character entered. Try again." << endl;
				continue;
			}
			break;
		}
		if (tolower(play_again) == 'y')
			continue;
		else
			break;
	}	//end main program loop

	//ending message
	cout << "\n\nEnd of program. Goodbye!\n";
	return 0;
}	//end main