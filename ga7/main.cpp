#include "foodtracker.h"
#include "food.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printFoods(vector<Food>& list) {
    for (int i = 0; i < list.size(); i++) {
        cout << i << ": " << list[i].toString() << endl;
    }
}

void writeNonFavoritesToFile(FoodTracker& tracker) {
    vector<Food> nonFavorites = tracker.getAllNotFavorited();
    ofstream outfile("nonfavorite.txt");
    for (int i = 0; i < nonFavorites.size(); i++) {
        outfile << nonFavorites[i].toCsvString() << endl;
    }
    outfile.close();
    cout << "Non favorited foods written to nonfavorite.txt" << endl;
}

int main() {
    FoodTracker foodTracker;
    ifstream infile("allfood.txt");
    string line;
    while (getline(infile, line)) {
        foodTracker.addFood(line);
    }
    infile.close();
    vector<Food> breads = foodTracker.getBreads();
    vector<Food> meats = foodTracker.getMeats();
    vector<Food> fruitsVeg = foodTracker.getFruitsVeg();
    vector<Food> dairy = foodTracker.getDairy();
    int input;
    for (int day = 1; day <= 28; day++) {
        printFoods(fruitsVeg);
        cout << "Enter index of favorite fruits/veg on day " << day << " or -1 if you don't have any: ";
        cin >> input;
        if (input >= 0) {
            foodTracker.addFavorite(fruitsVeg[input]);
        }
        printFoods(meats);
        cout << "Enter index of favorite meat on day " << day << " or -1 if you don't have any: ";
        cin >> input;
        if (input >= 0) {
            foodTracker.addFavorite(meats[input]);
        }
        printFoods(breads);
        cout << "Enter index of favorite bread on day " << day << " or -1 if you don't have any: ";
        cin >> input;
        if (input >= 0) {
            foodTracker.addFavorite(breads[input]);
        }
        printFoods(dairy);
        cout << "Enter index of favorite dairy on day " << day << " or -1 if you don't have any: ";
        cin >> input;
        if (input >= 0) {
            foodTracker.addFavorite(dairy[input]);
        }
    }
    writeNonFavoritesToFile(foodTracker);
    return 0;
}
