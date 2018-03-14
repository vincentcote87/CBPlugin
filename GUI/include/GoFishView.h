//
// CPSC 3720
// Assignment 1
//
/// GoFish View Header File
//
/// \author David Adams
/// \date Jan. 28, 2018
//
/// This file contains the class definition of the GoFish View class.

#ifndef GOFISHVIEW_H
#define GOFISHVIEW_H

#include <algorithm>
#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <cctype>

using std::invalid_argument;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::transform;
using std::tolower;
using std::cerr;
using std::numeric_limits;
using std::streamsize;
using std::array;


class GoFishView
{
/// Class Member Functions
public:
/// Default Constructor
//
/// constructs the GoFishView object
	GoFishView() {};

/// Destructor
//
/// destructs the GoFishView object
	virtual ~GoFishView() {};

/// printWelcome Function
//
/// prints a welcome message and prompts the user for the number of players
	virtual void printWelcome(char& playerNum);

/// printStatus
//
/// \param [out] currentPlayer the current player
/// \param [out] score the score of the current player
/// \param [out] playerHand the hand of the current player
/// prints the current player's status
	virtual void printStatus(const int& currentPlayer, const int& score, const string& playerHand);

/// printPlayerRequest
//
/// \param [out] playerLimit the maximum possible player number to request
/// \param [in] playerNum the number of the player making the request
/// \param [in] playerChoice the selection integer for the player being chosen
/// \param [out] rankIndex the number of the rank for the controller to choose from the Rank enumeration
/// prompts the user to request a player to ask for cards
	virtual void printPlayerRequest(const int& playerLimit, const int& playerNum, int& playerChoice, int& rankIndex);

/// printCardRequest
//
/// \param [in] cardChoice the string of the card being chosen
/// prompts the user to request a card from their chosen player
	virtual void printCardRequest(string& cardChoice);

/// printHasCards
//
/// \param [out] cardAmount int representing the number of cards being transferred
/// prints a message stating that the request was a success, and the given number of cards was transferred.
	virtual void printHasCards(const int& cardAmount);

/// printGoFish
//
/// prints the "Go Fish" message
	virtual void printGoFish();

/// printFinalScore
//
/// \param [out] currentPlayer the current player
/// \param [out] score the score of the current player
/// prints the player's final score
	virtual void printFinalScore(const int& currentPlayer, const int& score);

/// printGameOver
//
/// prints the game over message
	virtual void printGameOver();

/// clear function
//
/// \param [out] e the exception to be printed
/// prints the passed exception and clears the cin stream
	virtual void clear(const invalid_argument& e);

};

#endif