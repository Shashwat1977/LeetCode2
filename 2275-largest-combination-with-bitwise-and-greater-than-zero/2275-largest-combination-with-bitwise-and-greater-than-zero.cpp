class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int mx = 0;
        int cnt ;
        for(int i = 0;i<32;i++){
            cnt = 0;
            for(auto it:candidates){
                if(it&(1<<i)){
                    cnt++;
                }
            }
            mx = max(mx,cnt);
        }
        return mx;
    }
};