class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> se;
        int i = 0;
        int j = 0;
        int mx = 0;
        while(j<s.length()){
            if(se.find(s[j]) != se.end()){
                while(se.find(s[j])!=se.end()){
                se.erase(s[i]);
                i++;}
            }
            se.insert(s[j]);
            j++;
            int siz = se.size();
            mx = max(mx,siz);
        }
        return mx;
    }
};