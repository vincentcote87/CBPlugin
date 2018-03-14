//
// CPSC 3720
// Assignment 1
//
// GoFishModel Class Implementation File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the member function defintions for the GoFishModel class.

#include "GoFishModel.h"

// Constructor
//
// \param [in] deck the Deck representing the deck of cards in the game
// \param [in] dealLimit the int representing the maximum number of cards each player can be dealt
// \param [in] status the Status representing whether the game is over, running, or just starting
// constructs the GoFishModel object
GoFishModel::GoFishModel(Deck deck, int dealLimit, Status status)
	: _deck(deck), _dealLimit(dealLimit), _status(status)
{
	_deck.shuffle();
}


// getDeck Function
//
// \return Deck representing the game's deck
// function to return a Deck representing the game's deck object
Deck GoFishModel::getDeck()
{
	return _deck;
}

// getPlayers Function
//
// \return vector representing the players in the game
// returns the vector of players in the game
vector<Player> GoFishModel::getPlayers()
{
	return _players;
}

// addPlayers Function
//
// adds the given number of players to the vector of players in the game
void GoFishModel::addPlayers(const int& amount)
{
	if ((amount > 0) && (amount + getPlayers().size() <= 7))
	{
		for (int i = 0; i < amount; ++i)
		{
			int playerNum = (getPlayers().size() + 1);
			_players.push_back(Player(playerNum, 0));
		}
	}
}

// getDealLimit Function
//
// \return int representing the maximum number of cards each player can be dealt
// returns the maximum number of cards each player can be dealt
int GoFishModel::getDealLimit() const
{
	return _dealLimit;
}

// setDealLimit Function
//
// \param [in] dealLimit the int representing the maximum that the deal limit will be set to
// sets the maximum number of dealt cards to the given integer
void GoFishModel::setDealLimit(const int& dealLimit)
{
	_dealLimit = dealLimit;
}

// getStatus Function
//
// \return Status representing whether the game is over, starting, or running
// returns a Status representing whether the game is over, starting, or running
Status GoFishModel::getStatus()
{
	return _status;
}

// setStatus Function
//
// \param [in] status the Status representing what the _status variable will be set to
// sets a Status determining whether the game is over
void GoFishModel::setStatus(const Status& status)
{
	_status = status;
}

// dealCards Function
//
// deals the limit of cards to all players
void GoFishModel::dealCards()
{
	for (int i = 0; i < getDealLimit(); ++i)
	{
		for (int j = 0; j < getPlayers().size(); ++j)
		{
			_players[j].receiveCard(_deck.drawCard());
		}
	}
}