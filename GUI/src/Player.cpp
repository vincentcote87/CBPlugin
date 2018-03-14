//
// CPSC 3720
// Assignment 1
//
// Player Implementation File
//
// \author David Adams
// \date Jan. 27, 2018
//
// This file contains the class function defintions for the Player class.

#include "Player.h"

// sortBy function
// \param[in] Card1 One of the cards to be compared
// \param[in] Card2 One of the cards to be compared
//
//Helper function for sorting
bool sortBy(Card, Card);
// Constructor
//
// \param [in] score an integer representing the score of the player
// constructs a player object from the given parameters
Player::Player(int playerNum, int score)
    : _playerNum(playerNum), _score(score)
{
}

// getHand Function
//
// \return vector<Card> representing the player's hand
// returns the player's hand
vector<Card> Player::getHand()
{
    return _hand;
}

// getHandString Function
//
// \return string representing the player's hand
// returns the player's hand in string form
string Player::getHandString()
{
	string s = "";
	for (int i = 0; i < _hand.size(); ++i)
	{
		s = (s + to_string((i + 1)) + ") " + _hand[i].getCardString() + "\n");
	}
	return s;
}

// getPlayerNum Function
//
// \return int representing the player's number
// returns an integer representing the player's number
int Player::getPlayerNum() const
{
	return _playerNum;
}

// getScore Function
//
// \return int representing the player's score
// returns an integer representing the player's score
int Player::getScore() const
{
    return _score;
}

// getHandSize Function
//
// \return int representing the player's hand size
// returns an integer representing the player's hand size
int Player::getHandSize()
{
    return _hand.size();
}

// receiveCard Function
//
// \param[in] newCard the Card to be received by the player
// adds a card to the player's hand
void Player::receiveCard(const Card& newCard)
{
    _hand.push_back(newCard);
}

// countRank Function
//
// \param[in] value the Rank to be counted in player's hand
// \return int the number of cards with the given rank in the player's hand
// returns an integer representing how many cards of the given rank the player has
int Player::countRank(const Rank& value)
{
    int n = 0;
    for (int i = 0; i < getHandSize(); ++i)
    {
        if (getHand()[i].getRank() == value)
        {
            ++n;
        }
    }
    return n;
}

// giveCards Function
//
// \param[in] value the Rank of the card to be given
// \param[in] otherPlayer the Player to whom the cards will be given
// \return int representing how many cards of the given rank have been given
// finds cards in the hand of the given rank and gives them to the requesting player, also counting every card that is given
int Player::giveCards(const Rank& value, Player& otherPlayer)
{
    int n = 0;
    for (auto it = _hand.begin(); it != _hand.end(); )
        {
            if (value == it->getRank())
            {
                Card temp = *it;
				otherPlayer.receiveCard(temp);
				it = _hand.erase(it);
                ++n;
            }
			else
			{
				++it;
			}
        }
        return n;
}

/// takeCard Function
//
/// \param[in] indexOfHand the index of card to remove
/// \return Card the Card to remove
/// Takes the card out of the Players hand from the given index
Card Player::takeCard(int indexOfHand)
{
    Card cR = _hand[indexOfHand];
    _hand.erase(_hand.begin()+indexOfHand);
    return cR;
}

// receivePoint Function
//
// function to increase the player's score by one
void Player::receivePoint()
{
    ++_score;
}

// sortBy function
// \param[in] Card1 One of the cards to be compared
// \param[in] Card2 One of the cards to be compared
//
//Helper function for sorting
bool sortBy(Card c1, Card c2)
{
    string s1 = c1.getRankString();
    string s2 = c2.getRankString();
    return s1 < s2;
}

// sortHand Function
//
// sorts the players hand
void Player::sortHand()
{
    sort(_hand.begin(), _hand.end(), sortBy);
}


