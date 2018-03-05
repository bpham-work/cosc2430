#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "circularlinkedlist.h"
#include "player.h"
using namespace std;

double getRandomMoneyAmt() {
    return rand() % 1000 + 100;
}

void createPlayers(CircularLinkedList<Player>& players) {
    players.append(Player("John", getRandomMoneyAmt()));
    players.append(Player("Jazz", getRandomMoneyAmt()));
    players.append(Player("Foo", getRandomMoneyAmt()));
    players.append(Player("Bar", getRandomMoneyAmt()));
    players.append(Player("Baz", getRandomMoneyAmt()));
}

void printPlayers(CircularLinkedList<Player>& players) {
    for (int i = 0; i < 5; i++) {
        Player player = players.getNext();
        cout << player.toString() << endl;
    }
    cout << endl;
}

int getRoundTime(int round) {
    if (round == 1 || round == 2) {
        return 1;
    }
    return getRoundTime(round - 1) + getRoundTime(round - 2);
}

/**
 * This program adheres mostly to option 3:
 * Players will play for 30 minutes or until they lose 90% of
 * their original money.
 */
int main() {
    srand(time(NULL));
    CircularLinkedList<Player> players;
    createPlayers(players);
    cout << "---------- BEFORE PLAY ----------" << endl;
    printPlayers(players);

    int totalMinsPlayed = 0;
    int round = 1;
    cout << "---------- KNOCKED OUT PLAYERS ----------" << endl;
    while (totalMinsPlayed < 30) {
        int minsToPlay = getRoundTime(round);
        if ((totalMinsPlayed + minsToPlay) > 30) {
            minsToPlay = 30 - totalMinsPlayed;
        }
        totalMinsPlayed += minsToPlay;

        Player* player;
        for (int i = 0; i < 5; i++) {
            player = &(players.getNext());
            if (player->shouldStopPlaying()) {
                continue;
            }
            for (int k = 0; k < minsToPlay; k++) {
                player->deductMoney();
                if (player->shouldStopPlaying()) {
                    cout << player->toString() << "\t Round: " << to_string(round) << endl;
                    break;
                }
            }
        }
        round++;
    }

    cout << endl;
    cout << "---------- FINAL REPORT ----------" << endl;
    printPlayers(players);
    
    return 0;
}
