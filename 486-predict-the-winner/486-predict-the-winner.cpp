class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int i = 0;
        int j = n-1;
        int sum = helper(0,n-1,dp,nums);
         return 2*sum >= accumulate(nums.begin(), nums.end(), 0);
    }
    int helper(int i,int j,vector<vector<int>>& dp,vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int one = nums[i]+min(helper(i+2,j,dp,nums),helper(i+1,j-1,dp,nums));
        int two = nums[j] + min(helper(i+1,j-1,dp,nums),helper(i,j-2,dp,nums));
        return dp[i][j] = max(one,two);
    }
};