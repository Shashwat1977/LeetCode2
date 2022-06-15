class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        multiset<pair<int,int>> mp;
        for(int i = 0;i<arr.size();i++){
            mp.insert({__builtin_popcount(arr[i]),arr[i]});
        }
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};