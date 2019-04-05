/* Adiel Itzhak 313485286 */
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

Player::Player(string name , int num_of_cards){
    this->name = name;
    this->num_of_cards = num_of_cards;

    for (int j = 0; j < num_of_cards; j++) {
        Card* c = new Card;
         *c = Card::generate_card();
        plCards.push_back(c);
    }
}

Player::Player(const Player& otherPlayer){
    (*this) = otherPlayer;
}

string Player::getName() {
    return name;
}
int Player::getNumOfCards(){
    return num_of_cards;
}

void Player:: takeCard(){
    Card * c = new Card;
    *c = Card::generate_card();
    plCards.push_back(c);
    num_of_cards++;
}

void Player:: putCard(const int index){
    plCards.erase(plCards.begin() + index);
    num_of_cards--;
}

bool Player:: isEmpty(){
    return getNumOfCards() == 0;
}


bool Player::play(Card& current) {
    turnStat(current);
    int choose;

    while (true){

        cin >> choose;
        choose;

        if(choose > getNumOfCards() || choose <= 0 ){
            takeCard();
            return false;
        }

        else if(current.is_legal(*plCards.at(choose-1))){
            current = *(plCards.at(choose-1));
            putCard(choose-1);
            return true;
        }

        else cout << "You can't put " << *(plCards.at(choose-1)) << " on " << current << endl<< endl;
    }
}

void Player::turnStat(const Card& current){
    cout << "Current: " << current << endl;
    cout << name << " , your turn... " <<endl;
    cout << "Your cards: ";
    for (int i = 0; i < plCards.size(); ++i) {
        cout << "   (" << i+1 << ") " << *(plCards.at(i)) ;
    }
    cout << endl<< endl;
    cout << "----------------------";
    cout << endl<< endl;
}
