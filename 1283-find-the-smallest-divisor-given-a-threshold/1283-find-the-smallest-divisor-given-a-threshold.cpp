class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid = l+(h-l)/2;
            if(feasible(nums,threshold,mid))
                h = mid-1;
            else{
                l = mid+1;
            }
        }
        return l;
    }
    bool feasible(vector<int>& nums,int k,int mid){
        int sum = 0;
        for(int i=0;i<nums.size();i++){
                if(nums[i]%mid==0){
                    sum+=(nums[i]/mid);
                } else{
                    sum+=(nums[i]/mid)+1;
                }
            }
        if(sum<=k) return true;
        return false;
    }
};