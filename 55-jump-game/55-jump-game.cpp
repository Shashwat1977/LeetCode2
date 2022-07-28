class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        
        int lstone = n-1;
        for(int i=n-1; i>=0; --i) {
            if(i==n-1)
                dp[i] = 1;
            else {
                int len = lstone - i;
                if(len<=nums[i]) {
                    dp[i] = 1;
                    lstone = i;
                } else dp[i] = 0;
            }
        }
        return dp[0];
    }
};