#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
private:
    // food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;

    // cuisine -> ordered set of (rating, food)
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            // store as (-rating, food) so set sorts highest rating first
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        
        // remove old entry
        cuisineFoods[cuisine].erase({-oldRating, food});
        
        // update rating
        foodInfo[food].second = newRating;
        
        // insert new entry
        cuisineFoods[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        // first element of set is always the highest-rated
        return cuisineFoods[cuisine].begin()->second;
    }
};
