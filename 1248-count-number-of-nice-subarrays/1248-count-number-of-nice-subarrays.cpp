class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       vector<int> oddPos;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) oddPos.push_back(i);
        }
        if (oddPos.size() < k) return 0;
        oddPos.insert(oddPos.begin(), -1);
        oddPos.push_back(nums.size());
        
        for (int i = 1; i < oddPos.size()-k; i++) {
            res += (oddPos[i]-oddPos[i-1]) * (oddPos[i+k]-oddPos[i+k-1]); 
          
        }
        return res;
    }
};