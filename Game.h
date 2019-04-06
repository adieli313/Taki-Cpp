/* Adiel Itzhak 313485286 */
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>
#include <iostream>

using namespace std;

class Game {
private:

	// class members
	int numOfPlayers;
	int numOfCards;
	bool clockwise;
	vector<Player*> players;
	Card* current;
	Player* currPlayer;
	int currPlIndex;

	// class functions

    void  initialization();  // initial the game - players and cards;
    void nextTurn(); // set the player index for the next turn;
    int nextPlayer(); // set the next player according the current card;
    int getNumOfPlayers();
    vector<Player*> getPlayers();
    bool isGameOver(); // check if game over;

public:

	Game(); // constructor;
	~Game(); // destructor;
	void start(); // start the game;
};
#endif




