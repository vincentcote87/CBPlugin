#ifndef CHEATCONTROLLERTEST_H
#define CHEATCONTROLLERTEST_H
#include "CheatController.h"
#include "MockCard.cpp"
#include "MockDeck.cpp"
#include "Deck.h"
#include "MockCheatView.cpp"
#include "MockPlayer.cpp"
#include "Card.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <vector>
using namespace std;
using namespace ::testing;

class CheatControllerTest : public ::testing::Test
{
public:
	virtual void SetUp()
	{
		deck = new MockDeck();
		view = new MockCheatView();
		p1 = new MockPlayer(1);
		p2 = new MockPlayer(2);

		players.push_back(p1);
		players.push_back(p2);
		controller = new CheatController(players,view,deck);
		viewMock = dynamic_cast<MockCheatView*>(view);
		p1Mock = dynamic_cast<MockPlayer*>(p1);
		p2Mock = dynamic_cast<MockPlayer*>(p2);

		deckMock = dynamic_cast<MockDeck*>(deck);
	}

	virtual void TearDown()
	{
		delete controller;
		delete p1Mock;
		delete p2Mock;
		//delete p1Mock,p2Mock,p3Mock,p4Mock,p5Mock,p6Mock,p7Mock,p8Mock,p9Mock,p10Mock;
		//delete view, viewMock;
		//delete deck,deckMock;

	}

protected:
    CheatController* controller;
    CheatView* view;
    MockCheatView* viewMock;
    Deck* deck;
    MockDeck* deckMock;
	Player* p1;
	Player* p2;


    MockPlayer* p1Mock;
    MockPlayer* p2Mock;


    vector<Player*> players;

};
#endif
