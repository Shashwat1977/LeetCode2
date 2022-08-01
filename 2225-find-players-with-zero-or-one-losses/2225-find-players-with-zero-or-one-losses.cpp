class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> lose;
        map<int,int> win;
        for(auto it:matches){
            win[it[0]]++;
            lose[it[1]]++;
        }
        vector<vector<int>> vec;
        
        
        vector<int> temp;
        for(auto it:win){
            if(lose.find(it.first) == lose.end()){
                temp.push_back(it.first);
            }
        }
        vec.push_back(temp);
        temp.clear();
        for(auto it:lose){
            if(it.second ==1) temp.push_back(it.first);
        }
        vec.push_back(temp);
        return vec;
    }
};