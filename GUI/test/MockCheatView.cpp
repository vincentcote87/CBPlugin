#ifndef MOCKCHEATVIEW_CPP
#define MOCKCHEATVIEW_CPP

#include <gmock/gmock.h>
#include "CheatView.h"
#include "Card.h"

using namespace ::testing;
using std::string;
class MockCheatView : public CheatView
{
public:
	explicit MockCheatView()
	{
	}
	virtual ~MockCheatView()
	{
	}

	MOCK_METHOD0(welcomeMessage, void());
	MOCK_METHOD1(chooseCard, int(int MaxCard));
	MOCK_METHOD1(chooseNumPlayers, int(int maxPlayers));
	MOCK_METHOD1(displayPlayersHand, void(vector<Card> playersHand));
	MOCK_METHOD0(clearTerminal, void());
	MOCK_METHOD1(displayTurn, void(Player p1));
	MOCK_METHOD0(endTurn, void());
	MOCK_METHOD1(endingMessage, void(int winner));
	MOCK_METHOD2(callCheat, int(int numPlayers,int playerNum));
	MOCK_METHOD1(displayCard, void(string card));
	MOCK_METHOD0(continueDiscarding, bool());

};
#endif