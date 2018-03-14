//
// CPSC 3720
// Assignment 1
//
/// Deck Class Header File
//
/// \author David Adams
/// \date Jan. 24, 2018
//
/// This file contains the class definition for the Deck class.

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>

using std::vector;
using std::srand;
using std::random_shuffle;
using std::map;

class Deck
{
/// Class Members
private:
	vector<Card> _deckVector;

protected:
	map<int, Rank> rankMap = { {0, two}, {1, three}, {2, four}, {3, five}, {4, six}, {5, seven}, {6, eight}, {7, nine}, {8, ten}, {9, jack}, {10, queen}, {11, king}, {12, ace} };
	map<int, Suit> suitMap = { {0, hearts}, {1, diamonds}, {2, clubs}, {3, spades} };

/// Class Member Functions
public:
/// Constructor
//
/// constructs the deck object
	Deck();

/// Destructor
//
/// destructs the deck object
	virtual ~Deck() {};

/// getDeck function
//
/// \return vector<Card> of cards representing the deck
/// returns the private vector member of the deck
	virtual vector<Card> getDeck();

/// getSize function
//
/// \return int representing the size of the deck
/// returns the size of the deck
	virtual int getSize();

/// drawCard function
//
/// \return Card being drawn
/// returns the card being removed from the deck
	virtual Card drawCard();

/// shuffle function
//
/// void function to shuffle the cards in the deck
	virtual void shuffle();
};

#endif
