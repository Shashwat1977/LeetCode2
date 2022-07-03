class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        int s = pref.size();
        for(auto it:words){
            if(it.size()>=s){
                if(it.substr(0,s) == pref) cnt++;
            }
        }
        return cnt;
    }
};