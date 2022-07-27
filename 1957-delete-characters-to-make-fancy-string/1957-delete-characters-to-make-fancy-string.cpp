class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        if(s.size()<=2){
            return s;
        }
        for(int i = 0;i<s.size()-2;i++){
            if(s[i] == s[i+1] && s[i+1]== s[i+2]){
                continue;
            }else{
                res+= s[i];
            }
        }
        res+=s.substr(s.size()-2);
        return res;
    }
};