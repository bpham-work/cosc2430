#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
using namespace std;

class Player {
    int number;
    int age;
    double minsPlayed;

    public:
        Player();
        Player(int, int);
        int getNumber();
        int getAge();
        double getMinsPlayed();
        void addMinsPlayed(double mins);
        string toString();
        friend ostream& operator<<(ostream& out, Player& player);
};

Player::Player() {}

Player::Player(int number, int age) {
    this->number = number;
    this->age = age;
    this->minsPlayed = 0;
}

int Player::getNumber() {
    return this->number;
}

int Player::getAge() {
    return this->age;
}

double Player::getMinsPlayed() {
    return this->minsPlayed;
}

void Player::addMinsPlayed(double mins) {
    this->minsPlayed += mins;
}

string Player::toString() {
    string result = "";
    result += "Number: " + to_string(number) + " Age: " + to_string(age) + " Mins Played: " + to_string(minsPlayed);
    return result;
}

ostream& operator<<(ostream& out, Player& player) {
    out << player.toString();
    return out;
}

#endif
