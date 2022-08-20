class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto p = mp.begin();p!=mp.end();){
            if(p->second > 0){
                for(int i = 0;i<k;i++){
                    if(mp[p->first+i]>0){
                        mp[p->first+i]--;
                    }else{
                        return false;
                    }
                }
            }else{
                p++;
            }
        }
        return true;
    }
};