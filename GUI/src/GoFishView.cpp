//
// CPSC 3720
// Assignment 1
//
// GoFish View Header File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the class definition of the GoFish View class.

#include "GoFishView.h"

// printWelcome Function
//
// prints a welcome message and prompts the user for the number of players
void GoFishView::printWelcome(char& playerNum)
{
	bool entered = false;

	while (!entered)
	{
		try
		{
			cout << "Go Fish Game" << endl;
			cout << "How many (2-5) will be playing? (0 to quit)" << endl;
			cin >> playerNum;
			if (playerNum == '0' || playerNum == '2' || playerNum == '3' || playerNum == '4' || playerNum == '5')
			{
				entered = true;
				break;
			}
			else
			{
				throw invalid_argument("ERROR: Invalid number. Please try again.");
			}
		}
		catch (const invalid_argument& e)
		{
			clear(e);
		}
	}
}

// printStatus
//
// \param [out] currentPlayer the current player
// \param [out] score the score of the current player
// \param [out] playerHand the hand of the current player
// prints the current player's status
void GoFishView::printStatus(const int& currentPlayer, const int& score, const string& playerHand)
{
	cout << "Player " << currentPlayer << "'s score: " << score << endl;
	cout << "Player " << currentPlayer << "'s hand: " << endl;
	cout << playerHand;
}

// printPlayerRequest
//
// \param [out] playerLimit the maximum possible player number to request
// \param [in] playerNum the number of the player making the request
// \param [in] playerChoice the selection integer for the player being chosen
// \param [out] rankIndex the number of the rank for the controller to choose from the Rank enumeration
// prompts the user to request a player to ask for cards
void GoFishView::printPlayerRequest(const int& playerLimit, const int& playerNum, int& playerChoice, int& rankIndex)
{

	bool doneTurn = false;
	array<string, 13> rankArray = { "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace" };
	char playerTarget;
	string cardChoice;
	rankIndex = -1;

	while (!doneTurn)
	{
		// player check here
		try
		{
			cout << "Which player would you like to ask? (between 1 and " << playerLimit << ")" << endl;
			cin >> playerTarget;

			playerChoice = ((playerTarget - '0' - 1));
			if ((playerChoice < 0) || (playerChoice >= playerLimit) || playerNum == (playerChoice + 1))
			{
				throw invalid_argument("ERROR: Invalid player selection.");
			}
			else
			{
				doneTurn = true;
			}
		}
		catch (const invalid_argument& e)
		{
			clear(e);
		}
	}
	doneTurn = false;
	while (!doneTurn)
	{
		try
		{

			// way to check and handle card requests here
			printCardRequest(cardChoice);
			transform(cardChoice.begin(), cardChoice.end(), cardChoice.begin(), static_cast<int(*)(int)>(tolower));
			for (int i = 0; i < 13; ++i)
			{
				if (cardChoice == rankArray[i])
				{
					rankIndex = i;
					doneTurn = true;
					break;
				}
			}
			if (rankIndex == -1)
			{
				throw invalid_argument("ERROR: Invalid card selection.");
			}
		}
		catch (const invalid_argument& e)
		{
			clear(e);
		}
	}
}

// printCardRequest
//
// \param [in] cardChoice the string of the card being chosen
// prompts the user to request a card from their chosen player
void GoFishView::printCardRequest(string& cardChoice)
{
	cout << "Which card would you like to request? (two, three, jack, king, ace, etc.)" << endl;
	cin >> cardChoice;
}

// printHasCards
//
// \param [out] cardAmount int representing the number of cards being transferred
// prints a message stating that the request was a success, and the given number of cards was transferred.
void GoFishView::printHasCards(const int& cardAmount)
{
	cout << "Success! " << cardAmount << " card(s) transferred to your hand." << endl;
}

// printGoFish
//
// prints the "Go Fish" message
void GoFishView::printGoFish()
{
	cout << "Go fish!" << endl;
}

// printFinalScore
//
// \param [out] currentPlayer the current player
// \param [out] score the score of the current player
// prints the player's final score
void GoFishView::printFinalScore(const int& currentPlayer, const int& score)
{
	cout << "Player " << currentPlayer << "'s final score: " << score << endl;
}

// printGameOver
//
// prints the game over message
void GoFishView::printGameOver()
{
	cout << "Game Over" << endl;
}

// clear function
//
// \param [out] e the exception to be printed
// prints the passed exception and clears the cin stream
void GoFishView::clear(const invalid_argument& e)
{
	cerr << e.what() << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
