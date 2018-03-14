#include "CheatController.h"

CheatController::~CheatController()
{
	if(_dealersDeck != nullptr)
	{
		delete _dealersDeck;
		_dealersDeck = nullptr;
	}
	if(_view != nullptr)
	{
		delete _view;
		_view = nullptr;
	}

}

void CheatController::startGame()
{
	_dealersDeck->shuffle();
    _view->welcomeMessage();
    _numPlayers = _view->chooseNumPlayers(9);
}

void CheatController::initalDeal()
{
	int cardsPerPlayer = floor(_dealersDeck->getSize() / _numPlayers);
	for(int player=0; player<_numPlayers; player++)
	{
		for(int cardsDealt=0; cardsDealt<cardsPerPlayer; cardsDealt++)
		{
			_players[player]->receiveCard(_dealersDeck->drawCard());
		}
	}
	if(_dealersDeck->getSize() != 0)
		_pile = _dealersDeck->getDeck();
}

void CheatController::runGame()
{
	int index = -1;
	int handSize = -1;
	while(1)
	{
		++index;
        index = index % _numPlayers;
        _view->clearTerminal();
        int currentPlayer = turn(index);
        int handSize = _players[index]->getHandSize();
        if(handSize == 0)
        {
        	_view->endingMessage(++index);
        	break;
        }
	}
}

int CheatController::turn(int playerIndex)
{
	int numCardsDiscarded = 1;
	_view->displayTurn(playerIndex + 1);
	_players[playerIndex]->sortHand();
	_view->displayPlayersHand(_players[playerIndex]->getHand());
	_view->displayCard(_discard[_discardIndex]);

	int discard = _view->chooseCard(_players[playerIndex]->getHandSize());
	_pile.push_back(_players[playerIndex]->takeCard(discard-1));
	while(_view->continueDiscarding() && _players[playerIndex]->getHandSize() != 0)
	{
		_view->displayPlayersHand(_players[playerIndex]->getHand());
		discard = _view->chooseCard(_players[playerIndex]->getHandSize());

		_pile.push_back(_players[playerIndex]->takeCard(discard));

		++numCardsDiscarded;
		if(numCardsDiscarded == 4)
			break;
        _view->displayPlayersHand(_players[playerIndex]->getHand());
	}
	int playerCalledCheatIndex = _view->callCheat(_numPlayers, playerIndex);
	if(playerCalledCheatIndex != -1)
	{
		int playerGettingCards = playerCalledCheatIndex;
		if(didCheat(numCardsDiscarded))
			playerGettingCards = playerIndex;
		if(!_pile.empty())
		{
			for(vector<Card>::iterator it = _pile.begin(); it != _pile.end(); ++it)
			{
				_players[playerGettingCards]->receiveCard(*it);
			}
			if(!_pile.empty())
				_pile.clear();
		}
	}
	_view->endTurn();
	++_discardIndex;
	_discardIndex = _discardIndex % _discard.size();
}

bool CheatController::didCheat(int numCardsDiscarded)
{
	for(int i = _pile.size() - numCardsDiscarded; i<_pile.size();++i)
	{
		if(_pile[i].getRankString() != _discard[_discardIndex])
		{
			return true;
		}
	}
	return false;
}
