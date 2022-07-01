class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;
        while(n>0){
            if(n%2 == 0){
                cnt += n/2;
                n/=2;
            }else{
                cnt += (n-1)/2 + 1;
                n--;
                n/=2;
            }
        }
        return cnt-1;
    }
};