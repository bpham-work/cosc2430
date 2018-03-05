#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
    string name;
    double startingMoney;
    double currentMoney;
    public:
        Player();
        Player(string name, double money);
        string getName();
        double getMoney();
        void setMoney(double money);
        string toString();
        void deductMoney();
        bool shouldStopPlaying();
};

Player::Player() {}
Player::Player(string name, double money) :
    name(name), startingMoney(money), currentMoney(money) {}

string Player::getName() {
    return name;
}

double Player::getMoney() {
    return currentMoney;
}

void Player::setMoney(double money) {
    currentMoney = money;
}

void Player::deductMoney() {
    currentMoney *= 0.85;
}

bool Player::shouldStopPlaying() {
    return currentMoney < (startingMoney * 0.1);
}

string Player::toString() {
    string result;
    result += "Name: " + name +
        "\tInitial Money: $" + to_string(startingMoney) +
        "\tCurrent Money: $" + to_string(currentMoney);
    return result;
}

#endif
