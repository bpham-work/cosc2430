#ifndef BBBALL_GAME_H
#define BBBALL_GAME_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <climits>
#include "doublylinkedlist.h"
#include "linkedlist.h"
#include "player.h"
using namespace std;

class BasketballGame {
    Player lockerRoom[12];
    DoublyLinkedList<Player> benchPlayers;
    LinkedList<Player> courtPlayers;
    public:
        BasketballGame();
        void start();
    private:
        int getIndexOfOldestPlayer();
};

BasketballGame::BasketballGame() {
    srand(time(NULL));
    this->lockerRoom[12] = {};
    for (int i = 0; i < 12; i++) {
        int age = rand() % 50 + 20;
        lockerRoom[i] = Player(i+1, age);
    }
}

void BasketballGame::start() {
    for (int i = 0; i < 5; i++) {
        cout << lockerRoom[i].toString() << endl;
        courtPlayers.append(lockerRoom[i]);
    }
    for (int i = 5; i < 12; i++) {
        benchPlayers.append(lockerRoom[i]);
    }

    double gameTime = 0;
    double quarterTime = 0;
    while (gameTime <= 48) {
        int oldestIndex = this->getIndexOfOldestPlayer();
        Player* oldestPlayer = this->courtPlayers.get(oldestIndex);
        double playTime = oldestPlayer->getAge() / 10;
        gameTime += playTime;
        quarterTime += playTime;
        
        //cout << oldestIndex << endl;
        //cout << *oldestPlayer << endl;
        //Player* nextOnCourt = this->benchPlayers.peekHead();
        //cout << *nextOnCourt << endl;
        break;
        //this->benchPlayers.append(oldestPlayer);
        //courtPlayers.remove(oldestIndex);
        //courtPlayers.append(nextOnCourt);
    }
    cout << gameTime << endl;
}

int BasketballGame::getIndexOfOldestPlayer() {
    int oldestAge = INT_MIN;
    int indexOfOldest = -1;
    int counter = 0;
    for (LinkedList<Player>::iterator i = courtPlayers.begin(); !i.end(); i++) {
        cout << (*i)->toString() << endl;
        if ((*i)->getAge() > oldestAge) {
            indexOfOldest = counter;
            oldestAge = (*i)->getAge();
        }
        counter++;
    }
    return indexOfOldest;
}

#endif
