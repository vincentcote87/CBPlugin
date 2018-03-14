//
// CPSC 3720
// Assignment 1
//
// MockGoFishView File
//
// \author David Adams
// \date Feb. 6, 2018
//
// This file contains the class definition of the MockGoFishView class.

#include <gmock/gmock.h>
#include "GoFishView.h"

class MockGoFishView : public GoFishView
{
public:
	explicit MockGoFishView()
	{
	}
	virtual ~MockGoFishView()
	{
	}

	MOCK_METHOD1(printWelcome, void(char& playerNum));
	MOCK_METHOD3(printStatus, void(const int& currentPlayer, const int& score, const std::string& playerHand));
	MOCK_METHOD4(printPlayerRequest, void(const int& playerLimit, const int& playerNum, int& playerChoice, int& rankIndex));
	MOCK_METHOD1(printCardRequest, void(std::string& cardChoice));
	MOCK_METHOD1(printHasCards, void(const int& cardAmount));
	MOCK_METHOD0(printGoFish, void());
	MOCK_METHOD2(printFinalScore, void(const int& currentPlayer, const int& score));
	MOCK_METHOD0(printGameOver, void());
};