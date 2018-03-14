//
// CPSC 3720
// Assignment 1
//
/// GoFishModel Class Header File
//
/// \author David Adams
/// \date Jan. 27, 2018
//
/// This file contains the class definition for the GoFishModel class.

#ifndef GOFISHMODEL_H
#define GOFISHMODEL_H

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <vector>
#include <cassert>

using std::vector;

enum Status
{
	start,
	playing,
	done
};

class GoFishModel
{
	friend class GoFishController;
/// Class Members
private:
    int _dealLimit;
    Status _status;
	vector<Player> _players;
	Deck _deck;


/// Class Member Functions
public:

/// Constructor
//
/// \param [in] deck a Deck representing the deck of cards in the game
/// \param [in] dealLimit an int representing the maximum number of cards each player can be dealt
/// \param [in] status a Status representing whether the game is over, running, or just beginning
/// constructs the GoFishModel object
	GoFishModel(Deck deck = Deck(), int dealLimit = 5, Status status = start);

/// Destructor
//
/// destructs the GoFishModel object
	virtual ~GoFishModel() {};


/// getDeck Function
//
/// \return Deck representing the game's deck
/// function to return a Deck representing the game's deck object
    virtual Deck getDeck();

/// getPlayers Function
//
/// \return vector representing the players in the game
/// returns the vector of players in the game
    virtual vector<Player> getPlayers();

/// addPlayers Function
//
/// adds the given number of players to the vector of players in the game
	virtual void addPlayers(const int& amount);

/// getDealLimit Function
//
/// \return int representing the maximum number of cards each player can be dealt
/// returns the maximum number of cards each player can be dealt
	virtual int getDealLimit() const;

/// setDealLimit Function
//
/// \param [in] dealLimit the int representing the maximum that the deal limit will be set to
/// sets the maximum number of dealt cards to the given integer
	virtual void setDealLimit(const int& dealLimit);

/// getStatus Function
//
/// \return Status representing whether the game is over, starting, or running
/// returns a Status representing whether the game is over, starting, or running
	virtual Status getStatus();

/// setStatus Function
//
/// \param [in] status the Status representing what the _status variable will be set to
/// sets a Status determining whether the game is over
	virtual void setStatus(const Status& status);

/// dealCards Function
//
/// deals the limit of cards to all players
	virtual void dealCards();

};

#endif
