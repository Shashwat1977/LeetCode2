class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!= 0){
            return false;
        }
        sum/=2;
        int n = nums.size();
        vector<vector<bool>> dp(n,vector<bool> (sum+1,0));
        for(int i = 0;i<n;i++){
            dp[i][0] = 1;
        }
        if(sum>=nums[0]) dp[0][nums[0]]=1;
        for(int i= 1;i<n;i++){
            for(int j = 0;j<=sum;j++){
                bool non = dp[i-1][j];
                bool pick = false;
                if(nums[i]<=j) pick = dp[i-1][j-nums[i]];
                dp[i][j] = non||pick;
            }
        }
        return dp[n-1][sum];
    }
};