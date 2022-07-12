class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1,0);
        dp[0] = 1;
        for(int i = 1;i<=target;i++){
            int cnt = 0;
            for(auto& num:nums){
                if(i-num>=0) cnt+=dp[i-num];
            }
            dp[i] = cnt;
        }
        return dp[target];
    }
};