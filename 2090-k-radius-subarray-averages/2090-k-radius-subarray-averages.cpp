class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> temp(nums.size(),-1);
        int i = 0;int j = 0;
        long long sum = 0;
        int len = 2*k;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i< len){
                j++;
            }else if(j-i == len){
               temp[j-k] = sum/(len+1);
               sum -= nums[i];
               i++;j++;
            }
        }
        return temp;
    }
};