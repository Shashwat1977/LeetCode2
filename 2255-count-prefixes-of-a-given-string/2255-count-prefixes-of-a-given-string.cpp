class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(auto it:words){
            int i = it.size();
            if(it == s.substr(0,i)) cnt++;
        }
        return cnt;
    }
};