//
// CPSC 3720
// Assignment 1
//
// MockGoFishModel Class File
//
// \author David Adams
// \date Feb. 6, 2018
//
// This file contains the class definition for the MockGoFishModel class.

#include <gmock/gmock.h>
#include "GoFishModel.h"

class MockGoFishModel : public GoFishModel
{
public:
	explicit MockGoFishModel()
	{
	}
	virtual ~MockGoFishModel()
	{
	}

	MOCK_METHOD0(getDeck, Deck());
	MOCK_METHOD0(getPlayers, std::vector<Player>());
	MOCK_METHOD1(addPlayers, void(const int& amount));
	MOCK_METHOD0(getDealLimit, int());
	MOCK_METHOD1(setDealLimit, void(const int& dealLimit));
	MOCK_METHOD0(getStatus, Status());
	MOCK_METHOD1(setStatus, void(const Status& status));
	MOCK_METHOD0(dealCards, void());
};
