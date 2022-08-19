class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> mp;
        for(auto it:nums) freq[it]++;
        for(auto it:nums){
            if(freq[it] == 0) continue;
            if(mp[it] > 0){
                mp[it]--;
                freq[it]--;
                mp[it+1]++;
            }else if(freq[it]>0 && freq[it+1]>0 && freq[it+2]>0){
                    freq[it]--;
                    freq[it+1]--;
                    freq[it+2]--;
                    mp[it+3]++;
                } else{
                return false;
            }
            }
        
    return true;
    }
};