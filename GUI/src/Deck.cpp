//
// CPSC 3720
// Assignment 1
//
// Deck Class Implementation File
//
// \author David Adams
// \date Jan. 27, 2018
//
// This file contains the class function definitions for the Deck class.

#include "Deck.h"

// Constructor
//
// constructs the deck object
Deck::Deck()
{
	Rank tempRank;
	Suit tempSuit;

	for (int i = 0; i < rankMap.size(); ++i)
	{
		for (int j = 0; j < suitMap.size(); ++j)
		{
			tempRank = rankMap[i];
			tempSuit = suitMap[j];
			_deckVector.push_back(Card(tempRank, tempSuit));
		}
	}

}

// getDeck function
//
// \return vector<Card> of cards representing the deck
// returns the private vector member of the deck
vector<Card> Deck::getDeck()
{
	return _deckVector;
}

// getSize function
//
// \return int representing the size of the deck
// returns the size of the deck
int Deck::getSize()
{
	return _deckVector.size();
}

// drawCard function
//
// \return Card being drawn
// returns the card being removed from the deck
Card Deck::drawCard()
{
	Card top = _deckVector.back();
	_deckVector.pop_back();
	return top;
}

// shuffle function
//
// void function to shuffle the cards in the deck
void Deck::shuffle()
{
	srand((unsigned int)time(0));
	random_shuffle(_deckVector.begin(), _deckVector.end());
}
