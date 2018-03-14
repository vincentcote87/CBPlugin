//
// CPSC 3720
// Assignment 1
//
// MockCard Class File
//
// \author David Adams
// \date Feb. 6, 2018
//
// This file contains the class defintion for the MockCard class.

#include <gmock/gmock.h>
#include "Card.h"

using namespace ::testing;

class MockCard : public Card
{
public:
	explicit MockCard()
	{
	}
	virtual ~MockCard()
	{
	}

	MOCK_METHOD0(getRank, Rank());
	MOCK_METHOD0(getSuit, Suit());
	MOCK_METHOD0(getRankString, std::string());
	MOCK_METHOD0(getSuitString, std::string());
	MOCK_METHOD0(getCardString, std::string());
	virtual bool operator == (const Card& rhs)
	{
		return ((getRank() == rhs.getRank()) && (getSuit() == rhs.getSuit()));
	}
	virtual bool operator != (const Card& rhs)
	{
		return (!operator==(rhs));
	}
};