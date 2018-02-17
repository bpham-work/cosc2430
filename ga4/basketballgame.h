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
    Player finalList[12];
    public:
        BasketballGame();
        void start();
        void reportByMinsPlayed();
        void reportByAgeNumberMinsPlayed();
    private:
        int getIndexOfOldestPlayer();
        void updatePlayerPlayTimes(double mins);
        void createFinalList();
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
        double playTime = oldestPlayer->getAge() / 10.0;
        gameTime += playTime;
        quarterTime += playTime;
        this->updatePlayerPlayTimes(playTime);

        Player* nextOnCourt = this->benchPlayers.popHead();
        this->benchPlayers.append(*oldestPlayer);
        courtPlayers.remove(oldestIndex);
        courtPlayers.append(*nextOnCourt);
    }
    double overPlayedMins = gameTime - 48;
    this->updatePlayerPlayTimes(-1 * overPlayedMins);
    this->createFinalList();
}

int BasketballGame::getIndexOfOldestPlayer() {
    int oldestAge = INT_MIN;
    int indexOfOldest = -1;
    int counter = 0;
    for (LinkedList<Player>::iterator i = courtPlayers.begin(); !i.end(); i++) {
        if ((*i)->getAge() > oldestAge) {
            indexOfOldest = counter;
            oldestAge = (*i)->getAge();
        }
        counter++;
    }
    return indexOfOldest;
}

void BasketballGame::updatePlayerPlayTimes(double mins) {
    for (LinkedList<Player>::iterator i = courtPlayers.begin(); !i.end(); i++) {
        (*i)->addMinsPlayed(mins);
    }
}

void BasketballGame::createFinalList() {
    this->finalList[12] = {};
    int counter = 0;
    for (LinkedList<Player>::iterator i = courtPlayers.begin(); !i.end(); i++) {
        finalList[counter] = (**i);
        counter++;
    }
    for (DoublyLinkedList<Player>::iterator i = benchPlayers.begin(); !i.end(); i++) {
        finalList[counter] = (**i);
        counter++;
    }
}

void BasketballGame::reportByMinsPlayed() {
    // Sort by mins played
    for (int i = 1; i < 12; i++) {
        int k = i;
        while (k > 0 && finalList[k - 1].getMinsPlayed() < finalList[k].getMinsPlayed()) {
            Player temp = finalList[k];
            finalList[k] = finalList[k - 1];
            finalList[k - 1] = temp;
            k--;
        }
    }

    cout << "Number\tMinutes Played" << endl;
    for (int i = 0 ; i < 12; i++) {
        cout << finalList[i].getNumber() << "\t";
        cout << finalList[i].getMinsPlayed();
        cout << endl;
    }
}

void BasketballGame::reportByAgeNumberMinsPlayed() {
    // Sort by mins played
    for (int i = 1; i < 12; i++) {
        int k = i;
        while (k > 0 && finalList[k - 1].getMinsPlayed() < finalList[k].getMinsPlayed()) {
            Player temp = finalList[k];
            finalList[k] = finalList[k - 1];
            finalList[k - 1] = temp;
            k--;
        }
    }

    cout << "Number\tMinutes Played" << endl;
    for (int i = 0 ; i < 12; i++) {
        cout << finalList[i].getNumber() << "\t";
        cout << finalList[i].getMinsPlayed();
        cout << endl;
    }
}

#endif
