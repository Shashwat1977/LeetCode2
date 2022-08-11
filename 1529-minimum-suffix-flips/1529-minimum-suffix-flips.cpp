class Solution {
public:
    int minFlips(string target) {
        char c = '0';
        int j = 0;
        int cnt = 0;
        while(j<target.size()){
            while(target[j] == c){
                j++;
            }
            if(j<target.size()){
                cnt++;
                if(c == '0') c='1';
                else if(c == '1') c='0';
            }
            j++;
        }
        return cnt;
    }
};