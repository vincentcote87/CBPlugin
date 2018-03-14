//
// CPSC 3720
// Assignment 1
//
// GoFishModel Class Test File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the Test definition for the GoFishModel class.

#include <gtest/gtest.h>
#include "GoFishModel.h"

class GoFishModelTest : public::testing::Test
{
};

TEST(GoFishModelTest, defaultValues)
{
	GoFishModel m;
	EXPECT_EQ(52, m.getDeck().getSize());
	EXPECT_EQ(0, m.getPlayers().size());
	EXPECT_EQ(5, m.getDealLimit());
	EXPECT_EQ(start, m.getStatus());
}

TEST(GoFishModelTest, setValues)
{
	Deck d;
	GoFishModel m(d, 1, done);
	EXPECT_EQ(52, m.getDeck().getSize());
	EXPECT_EQ(0, m.getPlayers().size());
	EXPECT_EQ(1, m.getDealLimit());
	EXPECT_EQ(done, m.getStatus());
}

TEST(GoFishModelTest, addPlayersCheck)
{
	GoFishModel m;
	m.addPlayers(1);
	EXPECT_EQ(1, m.getPlayers().size());
	m.addPlayers(3);
	EXPECT_EQ(4, m.getPlayers().size());
	EXPECT_EQ(1, m.getPlayers()[0].getPlayerNum());
	EXPECT_EQ(4, m.getPlayers()[3].getPlayerNum());
}

TEST(GoFishModelTest, setDealLimitCheck)
{
	GoFishModel m;
	m.setDealLimit(3);
	EXPECT_EQ(3, m.getDealLimit());
}

TEST(GoFishModelTest, setStatusCheck)
{
	GoFishModel m;
	m.setStatus(done);
	EXPECT_EQ(done, m.getStatus());
}

TEST(GoFishModelTest, dealCardsCheck)
{
	Deck deck;

	GoFishModel m(deck, 5, start);
	m.addPlayers(5);
	m.dealCards();
	for (int i = 0; i < 5; ++i)
	{
		EXPECT_EQ(5, m.getPlayers()[i].getHandSize());
	}
	EXPECT_EQ(27, m.getDeck().getSize());
}