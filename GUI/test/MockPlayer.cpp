//
// CPSC 3720
// Assignment 1
//
// MockPlayer Class File
//
// \author David Adams
// \date Feb. 6, 2018
//
// This file contains the class defintion for the MockPlayer class.

#include <gmock/gmock.h>
#include "Player.h"

using namespace ::testing;

class MockPlayer : public Player
{
public:
	explicit MockPlayer(int pN): Player(pN){}
	virtual ~MockPlayer(){}

	MOCK_METHOD0(getHand, std::vector<Card>());
	MOCK_METHOD0(getHandString, std::string());
	MOCK_METHOD0(getPlayerNum, int());
	MOCK_METHOD0(getScore, int());
	MOCK_METHOD0(getHandSize, int());
	MOCK_METHOD1(receiveCard, void(const Card& newCard));
	MOCK_METHOD1(countRank, int(const Rank& value));
	MOCK_METHOD2(giveCards, int(const Rank& value, Player& otherPlayer));
	MOCK_METHOD0(receivePoint, void());
	MOCK_METHOD0(sortHand, void());
	MOCK_METHOD1(takeCard, Card(int indexOfHand));
};
