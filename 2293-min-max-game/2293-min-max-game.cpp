class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        while(nums.size() != 1){
            vector<int> v(nums.size()/2);
            for(int i = 0 ; i < v.size() ; i++){
                if(i % 2 == 0)
                    v[i] = min(nums[2 * i], nums[2 * i + 1]);
                else
                    v[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            nums = v;
        }
        return nums[0];

    }
};