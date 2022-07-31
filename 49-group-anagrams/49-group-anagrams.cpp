class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> vec(strs.size(),vector<int> (26,0));
        map<vector<int>,vector<string>> mp;
        for(int i = 0;i<strs.size();i++){
            for(int j = 0;j<strs[i].size();j++){
                vec[i][strs[i][j]-'a']++;
            }
            mp[vec[i]].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto it:mp){
            res.push_back(it.second);
        }
        return res;
    }
};