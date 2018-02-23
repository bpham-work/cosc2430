#ifndef REPLACEMENT_RECORD_H
#define REPLACEMENT_RECORD_H

#include <string>
#include <iostream>
using namespace std;

class ReplacementRecord {
    int playerIn;
    int playerOut;
    double gameTime;
    public:
        ReplacementRecord();
        ReplacementRecord(int, int, double);
        int getPlayerIn();
        int getPlayerOut();
        string getTimestamp();
};

ReplacementRecord::ReplacementRecord() {}

ReplacementRecord::ReplacementRecord(int a, int b, double c) : playerIn(a), playerOut(b), gameTime(c)  {}

int ReplacementRecord::getPlayerIn() {
    return this->playerIn;
}

int ReplacementRecord::getPlayerOut() {
    return this->playerOut;
}

string ReplacementRecord::getTimestamp() {
    int quarter = (this->gameTime / 12) + 1;
    double minInQuarter = this->gameTime - (12 * (quarter-1));
    return "Q" + to_string(quarter) + ":" + to_string(minInQuarter) + " or " +
        to_string(this->gameTime) + " minutes from beginning";
}

#endif
