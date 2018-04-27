#ifndef FOOD_H
#define FOOD_H

#include <string>
using namespace std;

class Food {
    public:
        string name;
        int category;
        float calories;
        bool favorite;
        Food();
        Food(string name, int category, float calories);
        void setAsFavorite();
        string toString();
        string toCsvString();
};

Food::Food() {}

Food::Food(string name, int category, float calories) {
    this->name = name;
    this->category = category;
    this->calories = calories;
    favorite = false;
}

void Food::setAsFavorite() {
    favorite = true;
}

string Food::toString() {
    return "Name: " + name + " Category: " + to_string(category) + " Calories: " + to_string(calories);
}

string Food::toCsvString() {
    return name + "," + to_string(category) + "," + to_string(calories);
}

#endif
