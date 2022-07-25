class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
        int n = words.size();
        vector<int> res;
        for(auto word:words){
            ans.push_back(func(word));
        }
        sort(ans.begin(),ans.end());
        for(auto q:queries){
            int val = func(q);
            int rem = upper_bound(ans.begin(),ans.end(),val) - ans.begin();
            res.push_back(n-rem);
        }
        return res;
    }
        int func(string s){
        map<int,int> mp;
        for(auto it:s) mp[it]++;
        return (*mp.begin()).second;
    }
};