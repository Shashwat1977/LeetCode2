class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int k) {
        int l = 1;
        int h = *max_element(piles.begin(),piles.end());
        while(l<=h){
            int mid = l+(h-l)/2;
            if(possible(piles,k,mid)){
                h=mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    bool possible(vector<int>& piles,int h,int k){
        int cnt = 0;
        for(int i = 0;i<piles.size();i++){
            cnt += piles[i]%k == 0?piles[i]/k:piles[i]/k + 1;
        }
        return cnt<=h;
    }
    
    
};