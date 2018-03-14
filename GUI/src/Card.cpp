//
// CPSC 3720
// Assignment 1
//
// Card Class Implementation File
//
// \author David Adams
// \date Jan. 27, 2018
//
// This file contains the member function defintions for the Card class.

#include "Card.h"

// Constructor
//
// \param[in] cardRank the rank of the card within the given suit, defaulted to two
// \param[in] suit the suit of the card, defaulted to hearts
// Constructs the card from the given parameters
Card::Card(Rank cardRank, Suit cardSuit)
	: _rank(cardRank), _suit(cardSuit)
{
}

// getRank function
//
// \return Rank of the card within its suit
// returns the rank of the card within its suit
Rank Card::getRank() const
{
	return _rank;
}

// getSuit function
//
// \return Suit of the card
// returns the suit of the card
Suit Card::getSuit() const
{
	return _suit;
}

// getRankString function
//
// \return string representing the rank of the card
// returns a string representing the rank of the card
string Card::getRankString() const
{
	switch(getRank())
	{
		case two: return "Two";
			break;
		case three: return "Three";
			break;
		case four: return "Four";
			break;
		case five: return "Five";
			break;
		case six: return "Six";
			break;
		case seven: return "Seven";
			break;
		case eight: return "Eight";
			break;
		case nine: return "Nine";
			break;
		case ten: return "Ten";
			break;
		case jack: return "Jack";
			break;
		case queen: return "Queen";
			break;
		case king: return "King";
			break;
		case ace: return "Ace";
			break;
		default: throw out_of_range("Card rank out of range");
	}
}

// getSuitString function
//
// \return string representing the suit of the card
// returns a string representing the suit of the card
string Card::getSuitString() const
{
	switch (getSuit())
	{
	case hearts: return "Hearts";
		break;
	case diamonds: return "Diamonds";
		break;
	case clubs: return "Clubs";
	   break;
	case spades: return "Spades";
	   break;
	default: throw out_of_range("Card suit out of range");
	}
}

// getCardString function
//
// \return string representing the card's rank and suit
// returns a string representing the card as a whole
string Card::getCardString() const
{
   return (getRankString() + " of " + getSuitString());
}

// == operator
//
// \return bool representing whether the cards are equal
bool Card::operator == (const Card& rhs)
{
	return ((getRank() == rhs.getRank()) && (getSuit() == rhs.getSuit()));
}

// != operator
//
// \return bool representing whether the cards are unequal
bool Card::operator != (const Card& rhs)
{
	return (!operator==(rhs));
}
