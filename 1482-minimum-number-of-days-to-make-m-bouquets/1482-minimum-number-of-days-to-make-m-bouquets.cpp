class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < m*k){
            return -1;
        }
        int l = 1;
        int h = *max_element(bloomDay.begin(),bloomDay.end());
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(mid,bloomDay,k,m)){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    bool possible(int mid,vector<int>& bloomDay,int k,int m){
        int cnt = 0;
        int z = 0;
        for(int i = 0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                z++;
                if(z == k){
                    cnt++;
                    z = 0;
                }
            }else{
                z = 0;
            }
        }
        return cnt>=m;
    }
};