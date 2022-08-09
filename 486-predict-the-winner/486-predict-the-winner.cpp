class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        int val = func(0,n-1,dp,nums);
        if(val>=0) return true;
        return false;
    }
    int func(int i,int j,vector<vector<int>>& dp,vector<int>& nums){
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];
        int one = nums[i]-func(i+1,j,dp,nums);
        int two = nums[j] - func(i,j-1,dp,nums);
        return dp[i][j] = max(one,two);
    }
};