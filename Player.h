/* Adiel Itzhak 313485286 */
#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <iostream>
#include <vector>
using namespace std;

class Player {
private:
    // class members
	string name;
	int num_of_cards;
	vector<Card*> plCards;
    // class functions
    void turnStat(const Card& current); // print the current state of the game;
    void takeCard(); // in case and the player don't have legal card to put;
    void putCard(const int index); // in casee and the player put legal card;
public:
	Player(string name , int num_of_cards); // constructor func;
    Player(const Player& otherPlayer); // copy constructor;
	bool play(Card&); // manage the player present play;
	string getName();
    vector<Card*> getPlCards();
    int getNumOfCards();
    bool isEmpty(); // check if the player has cards;


};
#endif



