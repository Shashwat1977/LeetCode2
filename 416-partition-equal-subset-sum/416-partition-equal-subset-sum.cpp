class Solution {
public:
    bool canPartition(vector<int>& vec) {
int sum = accumulate(vec.begin(),vec.end(),0);
        if(sum%2){
            return false;
        }
        int target = sum/2;
        int n = vec.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i = 0;i<n;i++){
            dp[i][0] = true;
        }
        if(vec[0]<=target) dp[0][vec[0]] = true;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<=target;j++){
                bool npick = dp[i-1][j];
                bool pick = false;
                if(vec[i]<=j){
                    pick = dp[i-1][j-vec[i]];
                }
                dp[i][j] = pick||npick;
            }
        }
        return dp[n-1][target];
    }
    
};