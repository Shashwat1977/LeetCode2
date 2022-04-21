class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        for(int i = 1;i<=n;i++){
            dp[i] = max(dp[i-1],(i>1?dp[i-2]:0)+nums[i-1]);
        }
        return dp[n];
    }
    
};