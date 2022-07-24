class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> right(n,0);
        right[n-1] = height[n-1];
        vector<int> left(n,0);
        left[0] = height[0];
        int mx = left[0];
        for(int i = 1;i<n;i++){
            mx = max(mx,height[i]);
            left[i] = mx;
        }
        mx = right[n-1];
        for(int i = n-2;i>=0;i--){
            mx = max(mx,height[i]);
            right[i] = mx;
        }
        vector<int> water(n,0);
        for(int i = 0;i<n;i++){
            water[i] = min(left[i],right[i]) - height[i];
        }
        return accumulate(water.begin(),water.end(),0);
    }
};