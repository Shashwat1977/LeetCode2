class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int prev = 0;int n = nums.size();
        int prev2 = nums[0];
        int curr = 0;
        for(int i = 1;i<n;i++){
            curr = max(prev2,prev+nums[i]);
            prev = prev2;
            prev2 = curr;
        }
        return curr;
    }
};