//
// CPSC 3720
// Assignment 1
//
// Player Test File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the Test defintion for the Player class.

#include <gtest/gtest.h>
#include "Player.h"

class PlayerTest : public::testing::Test
{
};

TEST(PlayerTest, defaultValues)
{
	Player player;
	EXPECT_EQ(1, player.getPlayerNum());
	EXPECT_EQ(0, player.getScore());
	EXPECT_EQ(0, player.getHand().size());
	EXPECT_EQ(0, player.getHandSize());
	EXPECT_EQ(0, player.countRank(two));
	EXPECT_EQ(0, player.countRank(ace));
	EXPECT_EQ(0, player.countRank(jack));
}

TEST(PlayerTest, definedValues)
{
	Player player(2, 20);
	EXPECT_EQ(2, player.getPlayerNum());
	EXPECT_EQ(20, player.getScore());
	EXPECT_EQ(0, player.getHand().size());
	EXPECT_EQ(0, player.getHandSize());
	EXPECT_EQ(0, player.countRank(two));
	EXPECT_EQ(0, player.countRank(ace));
	EXPECT_EQ(0, player.countRank(jack));
}

TEST(PlayerTest, scoreCheck)
{
	Player player(1, 1);
	EXPECT_EQ(1, player.getPlayerNum());
	EXPECT_EQ(1, player.getScore());

	player.receivePoint();
	EXPECT_EQ(2, player.getScore());
	for (int i = 1; i <= 10; ++i)
	{
		player.receivePoint();
		EXPECT_EQ(2+i, player.getScore());
	}
}

TEST(PlayerTest, handCheck)
{
	Player player1;
	Player player2(2, 0);
	EXPECT_EQ("", player1.getHandString());
	Card card(ace, spades);
	player1.receiveCard(card);
	EXPECT_EQ(1, player1.getHandSize());
	EXPECT_EQ(1, player1.countRank(ace));
	EXPECT_EQ("1) Ace of Spades\n", player1.getHandString());
}

TEST(PlayerTest, exchangeCheck)
{
	// re-establish that everything works from the start, for comparison
	Player player1;
	Player player2(2, 0);
	Card card(ace, spades);
	player1.receiveCard(card);
	EXPECT_EQ(1, player1.getHandSize());
	EXPECT_EQ(1, player1.countRank(ace));
	EXPECT_EQ("1) Ace of Spades\n", player1.getHandString());

	EXPECT_EQ(0, player2.getHandSize());
	EXPECT_EQ(0, player2.countRank(ace));
	EXPECT_EQ("", player2.getHandString());

	// first give a card he doesn't have
	player1.giveCards(king, player2);
	EXPECT_EQ(1, player1.getHandSize());
	EXPECT_EQ(1, player1.countRank(ace));
	EXPECT_EQ("1) Ace of Spades\n", player1.getHandString());

	EXPECT_EQ(0, player2.getHandSize());
	EXPECT_EQ(0, player2.countRank(ace));
	EXPECT_EQ("", player2.getHandString());

	// now give his only card
	player1.giveCards(ace, player2);
	EXPECT_EQ(1, player2.getHandSize());
	EXPECT_EQ(1, player2.countRank(ace));
	EXPECT_EQ("1) Ace of Spades\n", player2.getHandString());

	EXPECT_EQ(0, player1.getHandSize());
	EXPECT_EQ(0, player1.countRank(ace));
	EXPECT_EQ("", player1.getHandString());

	// now get more cards and exchange them
	Card card2(two, spades);
	Card card3(three, spades);
	Card card3A(three, hearts);
	Card card4(king, spades);
	player1.receiveCard(card2);
	player1.receiveCard(card3);
	player1.receiveCard(card3A);
	player2.receiveCard(card4);

	// make sure their hand sizes are correct
	EXPECT_EQ(2, player2.getHandSize());
	EXPECT_EQ(1, player2.countRank(ace));
	EXPECT_EQ(3, player1.getHandSize());
	EXPECT_EQ(1, player2.countRank(king));

	// now give their cards and check again
	player1.giveCards(three, player2);
	player2.giveCards(king, player1);
	EXPECT_EQ(3, player2.getHandSize());
	EXPECT_EQ(1, player2.countRank(ace));
	EXPECT_EQ(2, player2.countRank(three));
	EXPECT_EQ(2, player1.getHandSize());
	EXPECT_EQ(1, player1.countRank(king));

	// create a player who only has tens, and try giving them all away
	Player player3;
	Card card10A(ten, spades);
	Card card10B(ten, diamonds);
	Card card10C(ten, hearts);
	player3.receiveCard(card10A);
	player3.receiveCard(card10B);
	player3.receiveCard(card10C);
	EXPECT_EQ(3, player3.getHandSize());
	EXPECT_EQ(3, player3.countRank(ten));

	player3.giveCards(ten, player1);
	EXPECT_EQ(5, player1.getHandSize());
	EXPECT_EQ(3, player1.countRank(ten));
	EXPECT_EQ(0, player3.getHandSize());
	EXPECT_EQ(0, player3.countRank(ten));

}

TEST(PlayerTest, FullHandExchangeCheck)
{
	Player player1;
	Player player2(2, 0);

	// initialize player1's hand
	Card card11(ace, hearts);
	Card card12(two, hearts);
	Card card13(three, hearts);
	Card card14(four, hearts);
	Card card15(five, hearts);
	Card card16(six, hearts);
	Card card17(two, diamonds);
	player1.receiveCard(card11);
	player1.receiveCard(card12);
	player1.receiveCard(card13);
	player1.receiveCard(card14);
	player1.receiveCard(card15);
	player1.receiveCard(card16);
	player1.receiveCard(card17);

	// initialize player2's hand
	Card card21(ace, clubs);
	Card card22(two, clubs);
	Card card23(three, clubs);
	Card card24(four, clubs);
	Card card25(five, clubs);
	Card card26(six, clubs);
	Card card27(three, spades);
	player2.receiveCard(card21);
	player2.receiveCard(card22);
	player2.receiveCard(card23);
	player2.receiveCard(card24);
	player2.receiveCard(card25);
	player2.receiveCard(card26);
	player2.receiveCard(card27);

	// make sure everything is correct so far
	EXPECT_EQ(7, player1.getHandSize());
	EXPECT_EQ("1) Ace of Hearts\n2) Two of Hearts\n3) Three of Hearts\n4) Four of Hearts\n5) Five of Hearts\n6) Six of Hearts\n7) Two of Diamonds\n", player1.getHandString());
	EXPECT_EQ(7, player2.getHandSize());
	EXPECT_EQ("1) Ace of Clubs\n2) Two of Clubs\n3) Three of Clubs\n4) Four of Clubs\n5) Five of Clubs\n6) Six of Clubs\n7) Three of Spades\n", player2.getHandString());
	EXPECT_EQ(two, player1.getHand()[1].getRank());
	EXPECT_EQ(two, player1.getHand()[1].getRank());
	EXPECT_EQ(two, player2.getHand()[1].getRank());
	EXPECT_EQ(two, player2.getHand()[1].getRank());
	EXPECT_EQ(two, player1.getHand()[6].getRank());
	EXPECT_EQ(two, player1.getHand()[6].getRank());
	EXPECT_EQ(three, player2.getHand()[6].getRank());
	EXPECT_EQ(three, player2.getHand()[6].getRank());

	// now count player1's twos and player2's threes and make sure they match
	EXPECT_EQ(2, player1.countRank(two));
	EXPECT_EQ(2, player2.countRank(three));
	EXPECT_EQ(2, player1.countRank(two));
	EXPECT_EQ(2, player2.countRank(three));
	EXPECT_EQ(player2.countRank(three), player1.countRank(two));
	EXPECT_EQ(player2.countRank(three), player1.countRank(two));

	// now player1 gives his twos to player2
	player1.giveCards(two, player2);

	// now make sure everything is still correct
	EXPECT_EQ(5, player1.getHandSize());
	EXPECT_EQ("1) Ace of Hearts\n2) Three of Hearts\n3) Four of Hearts\n4) Five of Hearts\n5) Six of Hearts\n", player1.getHandString());
	EXPECT_EQ(9, player2.getHandSize());
	EXPECT_EQ("1) Ace of Clubs\n2) Two of Clubs\n3) Three of Clubs\n4) Four of Clubs\n5) Five of Clubs\n6) Six of Clubs\n7) Three of Spades\n8) Two of Hearts\n9) Two of Diamonds\n", player2.getHandString());
	EXPECT_EQ(three, player1.getHand()[1].getRank());
	EXPECT_EQ(three, player1.getHand()[1].getRank());
	EXPECT_EQ(two, player2.getHand()[1].getRank());
	EXPECT_EQ(two, player2.getHand()[1].getRank());
	EXPECT_EQ(six, player1.getHand()[4].getRank());
	EXPECT_EQ(six, player1.getHand()[4].getRank());
	EXPECT_EQ(three, player2.getHand()[6].getRank());
	EXPECT_EQ(three, player2.getHand()[6].getRank());
	EXPECT_EQ(two, player2.getHand()[7].getRank());
	EXPECT_EQ(two, player2.getHand()[8].getRank());
}

TEST(PlayerTest, FullHandExchangeVectorsCheck)
{
	Player player1;
	Player player2(2, 0);

	std::vector<Player> p;
	p.push_back(player1);
	p.push_back(player2);

	// initialize player1's hand
	Card card11(ace, hearts);
	Card card12(two, hearts);
	Card card13(three, hearts);
	Card card14(four, hearts);
	Card card15(five, hearts);
	Card card16(six, hearts);
	Card card17(two, diamonds);
	p[0].receiveCard(card11);
	p[0].receiveCard(card12);
	p[0].receiveCard(card13);
	p[0].receiveCard(card14);
	p[0].receiveCard(card15);
	p[0].receiveCard(card16);
	p[0].receiveCard(card17);

	// initialize player2's hand
	Card card21(ace, clubs);
	Card card22(two, clubs);
	Card card23(three, clubs);
	Card card24(four, clubs);
	Card card25(five, clubs);
	Card card26(six, clubs);
	Card card27(three, spades);
	p[1].receiveCard(card21);
	p[1].receiveCard(card22);
	p[1].receiveCard(card23);
	p[1].receiveCard(card24);
	p[1].receiveCard(card25);
	p[1].receiveCard(card26);
	p[1].receiveCard(card27);

	// make sure everything is correct so far
	EXPECT_EQ(7, p[0].getHandSize());
	EXPECT_EQ("1) Ace of Hearts\n2) Two of Hearts\n3) Three of Hearts\n4) Four of Hearts\n5) Five of Hearts\n6) Six of Hearts\n7) Two of Diamonds\n", p[0].getHandString());
	EXPECT_EQ(7, p[1].getHandSize());
	EXPECT_EQ("1) Ace of Clubs\n2) Two of Clubs\n3) Three of Clubs\n4) Four of Clubs\n5) Five of Clubs\n6) Six of Clubs\n7) Three of Spades\n", p[1].getHandString());
	EXPECT_EQ(two, p[0].getHand()[1].getRank());
	EXPECT_EQ(two, p[0].getHand()[1].getRank());
	EXPECT_EQ(two, p[1].getHand()[1].getRank());
	EXPECT_EQ(two, p[1].getHand()[1].getRank());
	EXPECT_EQ(two, p[0].getHand()[6].getRank());
	EXPECT_EQ(two, p[0].getHand()[6].getRank());
	EXPECT_EQ(three, p[1].getHand()[6].getRank());
	EXPECT_EQ(three, p[1].getHand()[6].getRank());

	// now count player1's twos and player2's threes and make sure they match
	EXPECT_EQ(2, p[0].countRank(two));
	EXPECT_EQ(2, p[1].countRank(three));
	EXPECT_EQ(2, p[0].countRank(two));
	EXPECT_EQ(2, p[1].countRank(three));
	EXPECT_EQ(p[1].countRank(three), p[0].countRank(two));
	EXPECT_EQ(p[1].countRank(three), p[0].countRank(two));

	// now player1 gives his twos to player2
	p[0].giveCards(two, p[1]);

	// now make sure everything is still correct
	EXPECT_EQ(5, p[0].getHandSize());
	EXPECT_EQ("1) Ace of Hearts\n2) Three of Hearts\n3) Four of Hearts\n4) Five of Hearts\n5) Six of Hearts\n", p[0].getHandString());
	EXPECT_EQ(9, p[1].getHandSize());
	EXPECT_EQ("1) Ace of Clubs\n2) Two of Clubs\n3) Three of Clubs\n4) Four of Clubs\n5) Five of Clubs\n6) Six of Clubs\n7) Three of Spades\n8) Two of Hearts\n9) Two of Diamonds\n", p[1].getHandString());
	EXPECT_EQ(three, p[0].getHand()[1].getRank());
	EXPECT_EQ(three, p[0].getHand()[1].getRank());
	EXPECT_EQ(two, p[1].getHand()[1].getRank());
	EXPECT_EQ(two, p[1].getHand()[1].getRank());
	EXPECT_EQ(six, p[0].getHand()[4].getRank());
	EXPECT_EQ(six, p[0].getHand()[4].getRank());
	EXPECT_EQ(three, p[1].getHand()[6].getRank());
	EXPECT_EQ(three, p[1].getHand()[6].getRank());
	EXPECT_EQ(two, p[1].getHand()[7].getRank());
	EXPECT_EQ(two, p[1].getHand()[8].getRank());
}

TEST(PlayerTest, takeCard)
{
    Player p1(1);
    Card c1(ace);
    Card c2(two);
    p1.receiveCard(c1);
    p1.receiveCard(c2);
    ASSERT_TRUE(p1.getHandSize() == 2);
    ASSERT_TRUE(p1.takeCard(1).getRankString() == c2.getRankString());
}

TEST(PlayerTest, sortHand)
{
    Player p1(1);
    Card c1(ace);
    Card c2(two);
    p1.receiveCard(c2);
    p1.receiveCard(c1);
    p1.sortHand();
    ASSERT_TRUE(p1.takeCard(0) == c1);
}

