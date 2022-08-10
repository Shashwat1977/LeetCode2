class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0];
        int ans =-1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>mn) ans=max(ans,nums[i]-mn);
            else mn = nums[i];
        }
        return ans;
    }
};