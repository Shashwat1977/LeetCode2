class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()<2) return 0;
        vector<int> temp = nums;
        sort(temp.begin(),temp.end());
        if(temp[n-1]<2*temp[n-2]) return -1;
        else{
            int ans = temp[n-1];
            for(int i = 0;i<nums.size();i++){
                if(nums[i] == ans) return i;
            }
        }
        return 0;
    }
};