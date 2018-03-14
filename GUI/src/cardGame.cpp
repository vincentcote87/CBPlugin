//
// CPSC 3720
// Assignment 1
//
// Card Game Main Program File
//
// \author David Adams
// \date Jan. 28, 2018
//
// This file contains the main program, which initializes and runs a card game.

#include <stdio.h>
#include <ctype.h>
#include "GoFishController.h"
#include "CheatController.h"
#include <iostream>

int main()
{
	char input = 'n';
	while(input != 'C' && input != 'G')
	{
		cout << "Do you want to play Cheat or GoFish? (c/g): ";
		cin >> input;
		input = toupper(input);
	}
	if(input == 'C')
	{
		Player* p1 = new Player(1);
	    Player* p2 = new Player(2);
    	Player* p3 = new Player(3);
    	Player* p4 = new Player(4);
    	Player* p5 = new Player(5);
    	Player* p6 = new Player(6);
    	Player* p7 = new Player(7);
    	Player* p8 = new Player(8);
    	Player* p9 = new Player(9);
    	Player* p10 = new Player(10);

    	vector<Player*> players = {p1,p2,p3,p4,p5,p6,p7,p8,p9,p10};
    	Deck* deck = new Deck();
    	CheatView* view = new CheatView();
		CheatController c(players,view,deck);
		c.startGame();
		c.initalDeal();
		c.runGame();
		delete p1;
		delete p2;
		delete p3;
		delete p4;
		delete p5;
		delete p6;
		delete p7;
		delete p8;
		delete p9;
		delete p10;
	}
	else if(input == 'G')
	{
	GoFishController g(new GoFishModel(), new GoFishView());
	g.play();
	}

	return 0;
}
