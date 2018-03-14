//
// CPSC 3720
// Assignment 1
//
// Card Class Test File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the Test defintions for the Card class.

#include <limits.h>
#include <gtest/gtest.h>
#include "Card.h"

class CardTest : public::testing::Test
{
};

TEST(CardTest, defaultValues)
{
	Card card;
	EXPECT_EQ(two, card.getRank());
	EXPECT_EQ(hearts, card.getSuit());
	EXPECT_EQ("Two", card.getRankString());
	EXPECT_EQ("Hearts", card.getSuitString());
	EXPECT_EQ("Two of Hearts", card.getCardString());
}

TEST(CardTest, aceOfSpades)
{
	Card card(ace, spades);
	EXPECT_EQ(ace, card.getRank());
	EXPECT_EQ(spades, card.getSuit());
	EXPECT_EQ("Ace", card.getRankString());
	EXPECT_EQ("Spades", card.getSuitString());
	EXPECT_EQ("Ace of Spades", card.getCardString());
}

TEST(CardTest, testRankString)
{
	Card card1(ace, spades);
	Card card2(two, spades);
	Card card3(three, spades);
	Card card4(four, spades);
	Card card5(five, spades);
	Card card6(six, spades);
	Card card7(seven, spades);
	Card card8(eight, spades);
	Card card9(nine, spades);
	Card card10(ten, spades);
	Card card11(jack, spades);
	Card card12(queen, spades);
	Card card13(king, spades);

	EXPECT_EQ("Ace", card1.getRankString());
	EXPECT_EQ("Two", card2.getRankString());
	EXPECT_EQ("Three", card3.getRankString());
	EXPECT_EQ("Four", card4.getRankString());
	EXPECT_EQ("Five", card5.getRankString());
	EXPECT_EQ("Six", card6.getRankString());
	EXPECT_EQ("Seven", card7.getRankString());
	EXPECT_EQ("Eight", card8.getRankString());
	EXPECT_EQ("Nine", card9.getRankString());
	EXPECT_EQ("Ten", card10.getRankString());
	EXPECT_EQ("Jack", card11.getRankString());
	EXPECT_EQ("Queen", card12.getRankString());
	EXPECT_EQ("King", card13.getRankString());
}

TEST(CardTest, testSuitString)
{
	Card card1(ace, hearts);
	Card card2(ace, diamonds);
	Card card3(ace, clubs);
	Card card4(ace, spades);

	EXPECT_EQ("Hearts", card1.getSuitString());
	EXPECT_EQ("Diamonds", card2.getSuitString());
	EXPECT_EQ("Clubs", card3.getSuitString());
	EXPECT_EQ("Spades", card4.getSuitString());
}

TEST(CardTest, comparingTwoCards)
{
	Card card1;
	Card card2(king, diamonds);
	EXPECT_EQ(false, card1 == card2);
	EXPECT_EQ(true, card1 != card2);
}