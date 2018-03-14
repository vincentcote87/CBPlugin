#ifndef CHEATCONTROLLER_H
#define CHEATCONTROLLER_H
#include "CheatView.h"
#include "Deck.h"
#include "Player.h"
#include "Card.h"
#include <algorithm>
#include <limits>
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <array>
#include <vector>
#include <cassert>
#include <math.h>
using std::string;
/**
*Implements the game Cheat.
*/
class CheatController
{
public:
	/**
	*Controller that sets up dependecy injection
	*@param vector<Player*> play The players that will be used in the game
	*@param CheatView* v  The view object
	*@param Deck* d the deck object that will be used
	*/
	CheatController(vector<Player*> &play, CheatView* v, Deck* d): _view(v), _players(play), _dealersDeck(d) {}
	/**
	*Class Destructor
	*/
	virtual ~CheatController();

	/**
	*Starts the game, creates players, and sets up the game.
	*/
	virtual void startGame();
	/**
	*Deals Cards to all Players. It deals 5 cards per player if there are 4-5 players and 7 if there are 2-3 players.
	*/
	virtual void initalDeal();
	/**typeid(a).name()
	*runGame does the loop that calls the appropriate functions to run the game until the game is won.
	*/
	virtual void runGame();
	/**
	*Calls a turn
	*@param playerIndex int that is the players number.
	*@return The index of the Player in the players vector taking a turn.
	*/
	virtual int turn(int);
	/**
	*Helper to turn, it checks if cheat is valid or not
	*@param numCardsDiscarded int that is the players number.
	*@return bool whether the player did cheat
	*/
	virtual bool didCheat(int);



private:
	/**
	*The view to be used
	*/
	CheatView* _view;
	/**
	*The vector of Player to be used
	*/
	vector<Player*> _players;
	/**
	*The Deck to be used 
	*/
	Deck* _dealersDeck;
	/**
	*The pile of cards discarded
	*/
	vector<Card> _pile;
	/**
	*The number of players
	*/
	int _numPlayers = 0;
	/**
	*The cards to be discarded
	*/
	vector<string> _discard = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
	/**
	*The index of the discard array
	*/
	int _discardIndex = 0;
};

#endif
