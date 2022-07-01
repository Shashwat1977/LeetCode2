class Solution {
public:
    int getSum(int n) {
  int sum = 0;
  int m = n;
  while(n > 0) {    
    m = n % 10;    
    sum = sum + m;    
    n = n / 10;    
  } 
  return sum;
}
    int countEven(int n) {
        int cnt = 0;
        for(int i = 1;i<=n;i++){
            if(getSum(i)%2 == 0) cnt++;
        }
        return cnt;
    }
};