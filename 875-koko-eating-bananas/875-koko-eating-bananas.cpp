class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int k) {
        int l = 1;
        int h = *max_element(piles.begin(),piles.end());
        while(l<=h){
            int mid = l+(h-l)/2;
            if(feasible(mid,piles,k)){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    bool feasible(int mid,vector<int>& piles,int k){
        int time=0;
        for(auto p : piles){
            time += p/mid;
            if(p%mid) time++;
        }
        
        if(time<=k) return true;
        return false;
    }
};