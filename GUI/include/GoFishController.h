//
// CPSC 3720
// Assignment 1
//
/// GoFish Controller Header File
//
/// \author David Adams
/// \date Jan. 28, 2018
//
/// This file contains the class definition of the GoFish Controller class.

#ifndef GOFISHCONTROLLER_H
#define GOFISHCONTROLLER_H

#include "GoFishModel.h"
#include "GoFishView.h"
#include <algorithm>
#include <limits>
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <array>
#include <vector>
#include <cassert>

class GoFishController
{
/// Class Members
private:
	GoFishModel* _model;
	GoFishView* _view;

/// Class Member Functions
public:

/// Constructor
//
/// \param [in] model of the MVC design
/// \param [in] view of the MVC design
/// constructs the GoFishController object
	GoFishController(GoFishModel* model = NULL, GoFishView* view = NULL);

/// Destructor
//
/// destructs the GoFishController object
	~GoFishController() {};

/// getModel Function
//
/// \return GoFishModel* representing the model of the game
/// returns the model of the GoFish game
	GoFishModel* getModel() const;

/// getView Function
//
/// \return GoFishView* representing the model of the game
/// returns the view of the GoFish game
	GoFishView* getView() const;

/// initPlayers Function
//
/// takes user input to set the number of players. Also sets the deal limit based on the number of players
	void initPlayers();

/// takeTurn Function
//
/// allows player to request a player and card
	void takeTurn(const int& playerIndex);

/// checkForWin Function
//
/// checks all players for sets, removes all sets, and checks for empty hands, ending the game if it's over
	void checkForWin();

/// update Function
//
/// runs the finer details of the game, keeping track of all of its components
	void update();

/// play Function
//
/// runs the game
	void play();

};

#endif