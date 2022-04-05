class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low+(high-low)/2;
            if(feasible(mid,nums,m)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    bool feasible(int mid,vector<int>& nums,int k){
        int count = 1;
        int sum =0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                sum = nums[i];
                count++;
                if(count>k) return false;
            }
        }
        return true;
    }
};