class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int mx = 0;
        for(auto it:houses){
            mx = max(mx,findr(heaters,it));
        }
        return mx;
    }
    int findr(vector<int>& heaters,int it){
        int l = 0;
        int h = heaters.size()-1;
        int ans = INT_MAX;
        while(l<=h){
            int m = l+(h-l)/2;
            if(heaters[m] == it){
                return 0;
            }else if(heaters[m]>it){
                ans = min(abs(heaters[m]-it),ans);
                h = m-1;
            }else{
                ans = min(abs(heaters[m]-it),ans);
                l = m+1;
            }
        }
        return ans;
    }
};