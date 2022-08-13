class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return helper(1,n,nums,dp);
    }
    int helper(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mx = INT_MIN;
        for(int k = i;k<=j;k++){
            mx = max(mx,nums[k]*nums[i-1]*nums[j+1]+helper(i,k-1,nums,dp)+helper(k+1,j,nums,dp));
        }
        return dp[i][j] = mx;
    }
};