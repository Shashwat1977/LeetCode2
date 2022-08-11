class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> second;
        unordered_map<char,int> first;
        for(auto it:s) second[it]++;
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            first[s[i]]++;
            second[s[i]]--;
            if(second[s[i]] == 0) second.erase(s[i]);
            if(first.size() == second.size()) cnt++;
        }
        return cnt;
    }
};