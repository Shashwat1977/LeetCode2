class FoodRatings {
public:
    map<string,map<int,set<string>>> mp;
    unordered_map<string,string> food;
    unordered_map<string,int> fr;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0;i<foods.size();i++){
            food[foods[i]] = cuisines[i];
            fr[foods[i]] = ratings[i];
            mp[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string foo, int newRating) {
        string cuisine = food[foo];
        int prev = fr[foo];
        mp[cuisine][prev].erase(foo);
        if(mp[cuisine][prev].empty()){
            mp[cuisine].erase(prev);
        }
        mp[cuisine][newRating].insert(foo);
        fr[foo] = newRating;
    }
    
    string highestRated(string cuisine) {
        int high = mp[cuisine].rbegin()->first;
        return *mp[cuisine][high].begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */