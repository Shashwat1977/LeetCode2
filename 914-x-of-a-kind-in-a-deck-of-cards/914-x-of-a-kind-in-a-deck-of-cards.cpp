class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        for(auto it:deck){
            mp[it]++;
        }
        int val = (*mp.begin()).second;
        int res = 0;
       for(auto pr:mp)
        {
            res=__gcd(pr.second,res);
        }
        return res>=2;

    }
};