#ifndef CHEATVIEW_H
#define CHEATVIEW_H
#include <iostream> 
#include "Deck.h"
#include "Player.h"
#include "Card.h"
#include <stdio.h>
#include <ctype.h>
using namespace std; 

class CheatView
{
public:
	CheatView(){}
	virtual ~CheatView(){}
	virtual void welcomeMessage();
	/**
	*Choose the Card number that will be checked against a player.
	*@return maxCard The players choice of Card.
	*@param The size of the hand.
	*/
	virtual int chooseCard(int);
	/**
	*Chooses the number of players that will play the game.
	*@param maxPlayers The maximum number of players
	*@return The number of players that will play.
	*/
	virtual int chooseNumPlayers(int);
	/**
	*Display the hand inputted.
	*@param hand Vector of Card to be displayed
	*/
	virtual void displayPlayersHand(vector<Card>);
	/**
	*Displays which Players' turn it is.
	*@param p1 The Player who's turn it is.
	*/
	virtual void displayTurn(Player);
	/**
	*The display message for the end of a turn.
	*/
	virtual void endTurn();
	/**
	*Displays the ending message to the game. To be displayed when the game has ended.
	*@param winner The player number of the winner.
	*/
	virtual void endingMessage(int);
	/**
	*Clears the terminal so that the player can't see the other players hand.
	*/
	virtual void clearTerminal();
	/**
	*Checks if anyone wants to call cheat
	*@return The index of the Player calling cheat
	*@param numPlayers The number of players in the game
	*@param playerNum The index of the current player whos turn it is
	*/
	virtual int callCheat(int, int);
	/**
	*Displays the current card to be discarded 
	*@param c The card face
	*/
	virtual void displayCard(string c);
	/**
	*Asks the player if he wants to discard another card 
	*@return true if they do want to, false otherwise
	*/
	virtual bool continueDiscarding();

};

#endif