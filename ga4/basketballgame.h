#ifndef BBBALL_GAME_H
#define BBBALL_GAME_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <climits>
#include "doublylinkedlist.h"
#include "linkedlist.h"
#include "player.h"
#include "replacementrecord.h"
using namespace std;

class BasketballGame {
    Player lockerRoom[12];
    DoublyLinkedList<Player> benchPlayers;
    LinkedList<Player> courtPlayers;
    LinkedList<ReplacementRecord> replacements;
    Player finalList[12];
    double gameTime = 0;
    public:
        BasketballGame();
        void start();
        void reportByMinsPlayed();
        void reportByAgeNumberMinsPlayed();
        void reportReplacements();
    private:
        int getIndexOfOldestPlayer();
        void replaceOldestPlayer(int oldestIndex, Player* oldestPlayer);
        void updatePlayerPlayTimes(double mins);
        void createFinalList();
};

BasketballGame::BasketballGame() {
    srand(time(NULL));
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

    while (gameTime <= 48) {
        int oldestIndex = this->getIndexOfOldestPlayer();
        Player* oldestPlayer = this->courtPlayers.get(oldestIndex);
        double playTime = oldestPlayer->getAge() / 10.0;
        this->gameTime += playTime;
        this->updatePlayerPlayTimes(playTime);

        if (gameTime > 48) break;
        this->replaceOldestPlayer(oldestIndex, oldestPlayer);
    }
    double overPlayedMins = this->gameTime - 48;
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

void BasketballGame::replaceOldestPlayer(int oldestIndex, Player* oldestPlayer) {
    Player* nextOnCourt = this->benchPlayers.popHead();
    this->benchPlayers.append(*oldestPlayer);
    courtPlayers.remove(oldestIndex);
    courtPlayers.append(*nextOnCourt);
    ReplacementRecord replacement(nextOnCourt->getNumber(), oldestPlayer->getNumber(), this->gameTime);
    replacements.append(replacement);

    this->reportReplacements();
}

void BasketballGame::updatePlayerPlayTimes(double mins) {
    for (LinkedList<Player>::iterator i = courtPlayers.begin(); !i.end(); i++) {
        (*i)->addMinsPlayed(mins);
    }
}

void BasketballGame::createFinalList() {
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
    // Sort by mins played descending
    for (int i = 1; i < 12; i++) {
        int k = i;
        Player pA = finalList[k];
        Player pB = finalList[k-1];
        while (k > 0 && pB.getMinsPlayed() < pA.getMinsPlayed()) {
            Player temp = finalList[k];
            finalList[k] = finalList[k - 1];
            finalList[k - 1] = temp;
            k--;
            pA = finalList[k];
            pB = finalList[k-1];
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
    // Sort by age ascending, number ascending, minutes played ascending
    for (int i = 1; i < 12; i++) {
        int k = i;
        Player pA = finalList[k];
        Player pB = finalList[k-1];
        while (k > 0 &&
                ((pB.getAge() > pA.getAge()) ||
                (pB.getAge() == pA.getAge() && pB.getNumber() > pA.getNumber()) ||
                (pB.getAge() == pA.getAge() && pB.getNumber() == pA.getNumber() && pB.getMinsPlayed() > pA.getMinsPlayed()))) {
            Player temp = finalList[k];
            finalList[k] = finalList[k - 1];
            finalList[k - 1] = temp;
            k--;
            pA = finalList[k];
            pB = finalList[k-1];
        }
    }

    cout << "Age\tNumber\tMinutes Played" << endl;
    for (int i = 0 ; i < 12; i++) {
        cout << finalList[i].getAge() << "\t";
        cout << finalList[i].getNumber() << "\t";
        cout << finalList[i].getMinsPlayed();
        cout << endl;
    }
}

void BasketballGame::reportReplacements() {
    cout << "Replacement Player\tReplacing\tReplacement Time in Quarter or in Total" << endl;
    for (LinkedList<ReplacementRecord>::iterator i = replacements.begin(); !i.end(); i++) {
        cout <<  (*i)->getPlayerIn() << "\t" << (*i)->getPlayerOut() << "\t" << (*i)->getTimestamp() << endl;
    }
}

#endif
