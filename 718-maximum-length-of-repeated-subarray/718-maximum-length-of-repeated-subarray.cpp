class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> prev(m+1,0);
        int mx = INT_MIN;
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1,0);
            for(int j = 1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{
                    curr[j] = 0;
                }
                 mx = max(curr[j],mx);
            }
           prev = curr;
        }
        return mx;
    }
};