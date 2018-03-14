//
// CPSC 3720
// Assignment 1
//
// Card Game Main Program File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the main program, which initializes and runs a card game.

#include "GoFishController.h"

// Constructor
//
// \param [in] model of the MVC design
// \param [in] view of the MVC design
// constructs the GoFishController object
GoFishController::GoFishController(GoFishModel* model, GoFishView* view)
	: _model(model), _view(view)
{
}

// getModel Function
//
// \return GoFishModel* representing the model of the game
// returns the model of the GoFish game
GoFishModel* GoFishController::getModel() const
{
	return _model;
}

// getView Function
//
// \return GoFishView* representing the model of the game
// returns the view of the GoFish game
GoFishView* GoFishController::getView() const
{
	return _view;
}

// initPlayers Function
//
// takes user input to set the number of players. Also sets the deal limit based on the number of players
void GoFishController::initPlayers()
{
	char playerNum;
	_view->printWelcome(playerNum);
	if (playerNum == '0')
	{
		_model->setStatus(done);
		update();
	}
	if (playerNum == '2' || playerNum == '3')
	{
		_model->addPlayers(playerNum - '0');
		_model->setDealLimit(7);
		_model->dealCards();
		_model->setStatus(playing);
	}
	else if (playerNum == '4' || playerNum == '5')
	{
		_model->addPlayers(playerNum - '0');
		_model->setDealLimit(5);
		_model->dealCards();
		_model->setStatus(playing);
	}
}

// takeTurn Function
//
// allows player to request a player and card
void GoFishController::takeTurn(const int& playerIndex)
{
	Rank targetCard;
	int rankIndex;
	int playerChoice;

	_view->printPlayerRequest(static_cast<int>(_model->getPlayers().size()), playerIndex+1, playerChoice, rankIndex);
	targetCard = Rank(rankIndex);

	// now that both requests have been established, make the trade if possible
	if (_model->getPlayers()[playerChoice].countRank(targetCard) > 0)
	{
		int cardsGiven = _model->getPlayers()[playerChoice].giveCards(targetCard, _model->getPlayers()[playerIndex]);
		_view->printHasCards(cardsGiven);
	}
	else
	{ // if not, then draw if there's still a deck
		_view->printGoFish();
		if (!_model->getDeck().getDeck().empty())
		{
			_model->getPlayers()[playerIndex].receiveCard(_model->_deck.drawCard());
		}
	}
}

// checkForWin Function
//
// checks all players for sets, removes all sets, and checks for empty hands, ending the game if it's over
void GoFishController::checkForWin()
{

	// check for sets, removing cards and awarding points if a set is found
	for (int i = 0; i < _model->getPlayers().size(); ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			if (_model->getPlayers()[i].countRank(Rank(j)) >= 4)
			{
				Player discardPile(-1, -1);
				_model->_players[i].giveCards(Rank(j), discardPile);
				_model->_players[i].receivePoint();
			}
		}
	}

	// check to see if anyone has an empty hand
	for (int i = 0; i < _model->getPlayers().size(); ++i)
	{
		if (_model->getPlayers()[i].getHandSize() < 1)
		{
			_model->setStatus(done);
			break;
		}
	}
}

// update Function
//
// runs the finer details of the game, keeping track of all of its components
void GoFishController::update()
{
	switch (_model->getStatus())
	{
	case start:
	{
		initPlayers();
		break;
	}
	case playing:
	{
		for (int i = 0; i < _model->getPlayers().size(); ++i)
		{
			if (_model->getStatus() == playing)
			{
				checkForWin();
				_view->printStatus(_model->getPlayers()[i].getPlayerNum(), _model->getPlayers()[i].getScore(), _model->getPlayers()[i].getHandString());
				takeTurn(i);
			}
		}
		if (_model->getStatus() == done)
		{
			update();
		}
		break;
	}
	case done:
	{
		_view->printGameOver();
		for (int i = 0; i < _model->getPlayers().size(); ++i)
		{
			_view->printFinalScore(_model->getPlayers()[i].getPlayerNum(), _model->getPlayers()[i].getScore());
		}
		break;
	}
	default:
		break;
	}
}

// play Function
//
// runs the game
void GoFishController::play()
{
	bool loop = true;
	while (loop)
	{
		update();
		if (_model->getStatus() == done) break;
	}
}
