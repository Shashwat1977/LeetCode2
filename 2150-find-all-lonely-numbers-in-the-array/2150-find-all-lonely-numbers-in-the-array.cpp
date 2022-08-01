class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> temp;
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second == 1 && mp.find(it.first+1) == mp.end() && mp.find(it.first-1) == mp.end()){
                temp.push_back(it.first);
            }
        }
        return temp;
    }
};