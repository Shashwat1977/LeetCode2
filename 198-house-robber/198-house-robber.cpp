class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for(int i = 2;i<nums.size();i++){
            int pick = dp[i-2]+nums[i];
            int non = dp[i-1];
            dp[i] = max(pick,non);
        }
        return dp[n-1];
    }
    
};