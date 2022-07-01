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
    int countBalls(int lowLimit, int highLimit) {
        vector<int> count(300);
        for(int i = lowLimit;i<=highLimit;i++){
            count[getSum(i)]++;
        }
        return *max_element(count.begin(),count.end());
    }
};