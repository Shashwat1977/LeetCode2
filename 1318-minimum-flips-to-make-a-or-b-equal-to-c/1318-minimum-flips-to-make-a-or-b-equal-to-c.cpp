class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        int cnt2 =0 ;
        for(int i = 0;i<31;i++){
            if(c&(1<<i)){
                if((a&1<<i) == 0 && (b&1<<i) == 0){
                    cnt++;
                }
            }else{
                if((a&(1<<i))){
                    cnt++;
                }
                if((b&(1<<i))) cnt++;
            }
        }
        return cnt;
    }
};