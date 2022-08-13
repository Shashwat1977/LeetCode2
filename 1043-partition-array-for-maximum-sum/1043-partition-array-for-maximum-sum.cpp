typedef long long ll;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        int ans = helper(0,arr,dp,k);
        return dp[0];
    }
    long long helper(int i,vector<int>& arr,vector<int>& dp,int k){
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int len = 0;
        long long mx = INT_MIN;
        ll sum = INT_MIN;
        for(int j = i;j< min((int)arr.size(),i+k);j++){
            len++;
            mx = max(mx,(long long)arr[j]);
            sum = max(sum,len*mx + helper(j+1,arr,dp,k));
        }
        return dp[i] = sum;
    }
};