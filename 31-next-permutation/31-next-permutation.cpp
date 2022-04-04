class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int s,e;
        for(s = n-2;s>=0;s--){
            if(nums[s]<nums[s+1]) break;
        }
        if(s<0) {
            reverse(nums.begin(),nums.end());
        }else{
            for(e=n-1;e>s;e--){
                if(nums[e]>nums[s]) break;
            }
            swap(nums[s],nums[e]);
        reverse(nums.begin()+s+1,nums.end());
        }
        
        
    }
};