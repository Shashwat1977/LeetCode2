class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k = (1<<maximumBit)-1;
        for(int i = 1;i<nums.size();i++){
            nums[i]=nums[i-1]^nums[i];
        }
        vector<int> temp;
        for(int i = nums.size()-1;i>=0;i--){
            temp.push_back(nums[i]^k);
            nums[i]^=nums[i];
        }
        return temp;
    }
};