#ifndef FOOD_TRACKER_H
#define FOOD_TRACKER_H

#include "doublylinkedlist/doublylinkedlist.h"
#include "bst/avlbst.h"
#include "food.h"
#include "splitter.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FoodTracker {
    DoublyLinkedList<Food> foodTracker;
    AvlBst<float, Food> breadsTree;
    AvlBst<float, Food> meatsTree;
    AvlBst<float, Food> fruitsVegTree;
    AvlBst<float, Food> dairyTree;
    public:
        vector<Food> getBreads();
        vector<Food> getMeats();
        vector<Food> getFruitsVeg();
        vector<Food> getDairy();
        void addFavorite(Food& food);
        void addFood(string& unparsedFood);
        vector<Food> getAllNotFavorited();
    private:
        void appendNonFavorites(vector<Food>& foods, vector<Food>& result);
};

vector<Food> FoodTracker::getBreads() {
    return breadsTree.getValuesInOrder();
}

vector<Food> FoodTracker::getMeats() {
    return meatsTree.getValuesInOrder();
}

vector<Food> FoodTracker::getFruitsVeg() {
    return fruitsVegTree.getValuesInOrder();
}

vector<Food> FoodTracker::getDairy() {
    return dairyTree.getValuesInOrder();
}

void FoodTracker::addFavorite(Food& food) {
    food.setAsFavorite();
    foodTracker.append(food);
    switch (food.category) {
        case 1:
            fruitsVegTree.insert(food.calories, food);
            break;
        case 2:
            meatsTree.insert(food.calories, food);
            break;
        case 3:
            breadsTree.insert(food.calories, food);
            break;
        case 4:
            dairyTree.insert(food.calories, food);
            break;
    }
}

void FoodTracker::addFood(string& unparsedFood) {
    vector<string> fields = util::split(unparsedFood, ',');
    Food food(fields[0], stoi(fields[1]), stof(fields[2]));
    switch (food.category) {
        case 1:
            fruitsVegTree.insert(food.calories, food);
            break;
        case 2:
            meatsTree.insert(food.calories, food);
            break;
        case 3:
            breadsTree.insert(food.calories, food);
            break;
        case 4:
            dairyTree.insert(food.calories, food);
            break;
    }
}

vector<Food> FoodTracker::getAllNotFavorited() {
    vector<Food> result;
    vector<Food> breads = breadsTree.getValuesInOrder();
    vector<Food> meats = meatsTree.getValuesInOrder();
    vector<Food> fruitsVeg = fruitsVegTree.getValuesInOrder();
    vector<Food> dairy = dairyTree.getValuesInOrder();
    appendNonFavorites(fruitsVeg, result);
    appendNonFavorites(meats, result);
    appendNonFavorites(breads, result);
    appendNonFavorites(dairy, result);
    return result;
}

void FoodTracker::appendNonFavorites(vector<Food>& foods, vector<Food>& result) {
    for (int i = 0; i < foods.size(); i++) {
        if (!foods[i].favorite) {
            result.push_back(foods[i]);
        }
    }
}

#endif
