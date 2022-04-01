class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 1;
        int end = nums.size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid-1]<nums[mid]) start = mid+1;
            else{
                end = mid-1;
            }
        }
        return end;
    }
};