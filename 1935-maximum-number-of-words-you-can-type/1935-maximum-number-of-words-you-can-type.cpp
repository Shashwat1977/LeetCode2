class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> mp;
        for(auto it:brokenLetters) mp[it]++;
        bool flag = true;
        text+=" ";
        int cnt = 0;
        for(int i = 0;i<text.size();i++){
            if(text[i] == ' '){
                if(flag) cnt++;
                flag = true;
            }else{
                if(mp[text[i]] == 1) flag = false;
            }
        }
        return cnt;
    }
};