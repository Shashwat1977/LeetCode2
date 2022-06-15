class Solution {
public:
    int minBitFlips(int start, int goal) {
        int t = start^goal;
        int cnt =0 ;
        while(t){
            t = t&(t-1);
            cnt++;
        }
        return cnt;
    }
};