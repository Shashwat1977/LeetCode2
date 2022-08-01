class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vector<int>> mp;
        for(int i = 0;i<g.size();i++){
            mp[g[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(auto it:mp){
            int val  = it.first;
            vector<int> temp = it.second;
            vector<int> r;
            for(int i = 0;i<temp.size();i++){

                r.push_back(temp[i]);
                if(r.size() == val){res.push_back(r); r.clear(); }
            }
        }
        return res;
    }
};