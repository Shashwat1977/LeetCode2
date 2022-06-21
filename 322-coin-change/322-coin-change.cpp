class Solution {
public:
    int coinChange(vector<int>& arr, int x) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(x+1,1e9));
        for(int i = 0;i<=x;i++){
            if(i%arr[0] == 0){
                dp[0][i] = i/arr[0];
            }
        }
        for(int i = 0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<=x;j++){
                int no = dp[i-1][j];
                int pick = 1e9;
                if(arr[i]<=j){
                    pick = 1+dp[i][j-arr[i]];
                }
                dp[i][j] = min(pick,no);
            }
        }
        if(dp[n-1][x] != 1e9){
            return dp[n-1][x];
        }else{
            return -1;
        }
    }
    
};