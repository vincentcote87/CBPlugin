//
// CPSC 3720
// Assignment 1
//
// MockDeck Class File
//
// \author David Adams
// \date Feb. 6, 2018
//
// This file contains the class defintion for the MockDeck class.

#include <gmock/gmock.h>
#include "Deck.h"

using namespace ::testing;

class MockDeck : public Deck
{
public:
	explicit MockDeck(){}
	virtual ~MockDeck(){}

	MOCK_METHOD0(getDeck, std::vector<Card>());
	MOCK_METHOD0(getSize, int());
	MOCK_METHOD0(drawCard, Card());
	MOCK_METHOD0(shuffle, void());
};
