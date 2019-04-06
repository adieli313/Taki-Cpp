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


    currPlIndex = 0; // rand() % getNumOfPlayers();



    while(true){
        currPlayer = players[currPlIndex];
        if((*currPlayer).play(*current)){
            if(isGameOver()){
                cout << endl <<(*currPlayer).getName() << " WINS!";
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
    if(cin.fail() || numOfPlayers <= 0) throw string("ilegal number of players");

    cout << "How many cards?" << endl;
    cin >>  numOfCards;
    if(cin.fail() || numOfCards <= 0) throw string("ilegal number of cards");


    for (int i = 0; i < numOfPlayers; i++)
    {
        cout << "Player number " << i + 1 << " name?" << endl;
        string name;
        cin >>  name;
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
