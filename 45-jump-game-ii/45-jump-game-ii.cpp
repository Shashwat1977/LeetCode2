class Solution {
public:
    int jump(vector<int>& nums) {
        int curr = 0;
        int mx = INT_MIN;
        int jump = 0;
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            if(mx< nums[i]+i){
                mx = nums[i]+i;
            }
            if(i == curr){
                curr = mx;
                jump++;
            }
        }
        return jump;
    }
};