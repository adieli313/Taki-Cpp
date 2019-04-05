/* Adiel Itzhak 313485286 */
#include "Game.h"
#include <iostream>
#include <vector>

using namespace std;

 Game::Game(){
    numOfPlayers = 0;
    numOfCards = 0;
    clockwise = true;
}
Game::~Game() {
    auto idx = players.begin();
    Player * playerToDelete;
    while (idx != players.end()) {
        playerToDelete = (*idx);
        delete playerToDelete;
        playerToDelete = NULL;
        idx = players.erase(idx);
    }
    if (current != NULL)
        delete current;
    current = NULL;
    if (current != NULL)
        delete current;
    current = NULL;
}

void Game::start()
{
    try{
        initialization();
    }catch(std::string& message) {
        std::cout << message << endl;
        return;
    }


    currPlIndex = rand() % getNumOfPlayers();



    while(true){
        currPlayer = players[currPlIndex];
        if((*currPlayer).play(*current)){
            if(isGameOver()){
                cout << endl << "*****     "<< (*currPlayer).getName() << " WINS!!! " << "     *****" ;
                return;
            }

        }
        nextPlayer();
    }


}

void Game::initialization()
{

    cout << "How many players?" << endl;
    cin >>  numOfPlayers;
    cout << "How many cards?" << endl;
    cin >>  numOfCards;

    for (int i = 0; i < numOfPlayers; i++)
    {
        cout << "Player number " << i + 1 << " name?" << endl;
        string name;
        cin >>  name;
        vector<Card> cards;
        players.push_back(new Player(name, numOfCards));

    }
    current = new Card;
    (*current) = Card::generate_card();

}


int Game::getNumOfPlayers(){
    return numOfPlayers;
}


void Game::nextTurn(){
     if(clockwise) {

         currPlIndex = (currPlIndex+1) % getNumOfPlayers() ;
     }
     else currPlIndex =  (currPlIndex-1) % getNumOfPlayers() ;
 }
int Game::nextPlayer(){

    sign currCardSign = (*current).get_sign();
    switch (currCardSign) {

        case sign::PLUS : break;

        case sign::CD : {
            clockwise = !clockwise ;
            nextTurn();
            break;
        }

        case sign::STOP : {
            nextTurn();
            nextTurn();
            break;
        }
        default: nextTurn();
    }

 }


bool Game::isGameOver(){
     return (*currPlayer).isEmpty();
 }
//int Game::operator ++(int nb)
//{
//    if (nb == this->getPlayers().size())
//    {
//        nb = 0;
//    }
//    else
//    {
//        nb++;
//    }
//}
//
//int Game::operator --(int nb)
//{
//    if (nb == 0)
//    {
//        nb = this->getPlayers().size() - 1;
//    }
//    else
//    {
//        nb--;
//    }
//}

