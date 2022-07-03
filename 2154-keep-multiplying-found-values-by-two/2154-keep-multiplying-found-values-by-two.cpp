class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        while(true){
            if(mp.find(original) == mp.end()){
                return original;
            }else{
                original*=2;
            }
        }
        return 0;
    }
};