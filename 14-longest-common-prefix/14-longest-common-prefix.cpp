class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = "";
        int cnt = 0;
        for(int i = 0;i<strs[0].size();i++){
            char ch = strs[0][i];
            bool flag = true;
            for(int j =1 ;j<strs.size();j++){
                if(i>=strs[j].size()){
                    flag = false;break;
                }if(strs[j][i] != ch){
                    flag = false;break;
                }
            }
            if(flag){
                temp+=ch;
            }else{
                break;
            }
        }
        return temp;
    }
};