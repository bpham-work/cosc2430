#include <iostream>
#include "doublylinkedlist.h"
#include "linkedlist.h"
#include "basketballgame.h"
using namespace std;

int main() {
    BasketballGame game;
    game.start();
    game.reportByMinsPlayed();
    game.reportByAgeNumberMinsPlayed();
    return 0;
}
