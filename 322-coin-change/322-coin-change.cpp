class Solution {
public:
    int coinChange(vector<int>& arr, int x) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(x+1,-1));
	int ans = helper(n-1,x,arr,dp);
	if(ans >= 1e9){
		return -1;
	}else{
		return ans;
	}
    }
    int helper(int i,int target,vector<int>& arr,vector<vector<int>>& dp){
	if(i == 0){
		if(target%arr[0] == 0) return target/arr[0];
		else return 1e9;
	}
	if(dp[i][target] != -1) return dp[i][target];
	int notpick = helper(i-1,target,arr,dp);
	int pick = INT_MAX;
	if(arr[i] <= target){
		pick = 1+helper(i,target-arr[i],arr,dp);
	}
	return dp[i][target] = min(notpick,pick);
}
};