class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:t) mp[it]--;
        long long res = 0;
        for(auto it:mp) res+=abs(it.second);
        return res;
    }
};