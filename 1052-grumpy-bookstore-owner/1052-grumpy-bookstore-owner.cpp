class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        long long s = 0;
        for(int i = 0;i<n;i++){
            if(grumpy[i] == 0){ s += customers[i]; customers[i] = 0;}
          
        }
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = INT_MIN;
        while(j<n){
            sum+=customers[j];
            if((j-i + 1) == minutes){
                ans = max(ans,sum);
            }else if((j-i+1 )> minutes){
                sum-=customers[i];
                i++;
                if((j-i + 1) == minutes)
                    ans = max(ans,sum);
            }
            j++;
        }
        return s+ans;
    }
};