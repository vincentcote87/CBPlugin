//
// CPSC 3720
// Assignment 1
//
/// Card Class Header File
//
/// \author David Adams
/// \date Jan. 23, 2018
//
/// This file contains the class defintions for the Card class.

#ifndef CARD_H
#define CARD_H

#include <string>
#include <stdexcept>

using std::string;
using std::out_of_range;

/// Suit enumerator
/// Enumerator to define the possible ranks of any card
enum Suit
{
	diamonds,
	hearts,
	clubs,
	spades
};

/// Rank enumerator
/// Enumerator to define the possible ranks of any card
enum Rank
{
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace
};

class Card
{
	/// Class Members
private:
	Rank _rank;
	Suit _suit;

	/// Class Member Functions
public:

	/// Constructor
	//
	/// \param[in] cardRank the rank of the card within the given suit, defaulted to two
	/// \param[in] suit the suit of the card, defaulted to hearts
	/// Constructs the card from the given parameters
	Card(Rank cardRank = two, Suit suit = hearts);

	/// Destructor
	//
	/// destructs the card object
	virtual ~Card() {};

	/// getRank function
	//
	/// \return Rank the rank of the card within its suit
	/// returns the rank of the card within its suit
	virtual Rank getRank() const;

	/// getSuit function
	//
	/// \return Suit the suit of the card
	/// returns the suit of the card
	virtual Suit getSuit() const;

	/// getRankString function
	//
	/// \return string a string representing the rank of the card
	/// returns a string representing the rank of the card
	virtual string getRankString() const;

	/// getSuitString function
	//
	/// \return string a string representing the suit of the card
	/// returns a string representing the suit of the card
	virtual string getSuitString() const;

	/// getCardString function
	//
	/// \return string a string representing the card's rank and suit
	/// returns a string representing the card as a whole
	virtual string getCardString() const;

	/// == operator
	//
	/// \return bool a boolean representing whether the cards are equal
	virtual bool operator==(const Card& rhs);

	/// != operator
	//
	/// \return bool a boolean representing whether the cards are unequal
	virtual bool operator != (const Card& rhs);


};

#endif
