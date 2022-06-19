class Solution {
public:
    int maxDistance(vector<int>& position, int k) {
        int l = 1;
        int h = 1e9+7;
        sort(position.begin(),position.end());
        while(l<=h){
            int m = l+(h-l)/2;
            if(possible(m,position,k)){
                l = m+1;
            }else{
                h = m-1;
            }
        }
        return h;
    }
    bool possible(int m,vector<int>& position,int k){
        int cnt = 1;
        int x = position[0];
        for(int i = 1;i<position.size();i++){
            if(position[i]-x >= m){
                cnt++;
                x = position[i];
            }
        }
        return cnt>=k;
    }
};