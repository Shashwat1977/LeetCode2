class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        int pre = -1;
        return func(0,nums,dp,-1);
    }
    int func(int i,vector<int>& nums,vector<vector<int>>& dp,int pre){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][pre+1]!= -1) return dp[i][pre+1];
        int mx = func(i+1,nums,dp,pre);
        if(pre == -1 || nums[i]>nums[pre]){
            mx = max(mx,1+func(i+1,nums,dp,i));
        }
        return dp[i][pre+1] = mx;
    }
};