class Solution {
public:
    int subarraysWithKDistinct(vector<int>& s, int k) {
        return sub(s,k)-sub(s,k-1);
    }
    int sub(vector<int>& s,int k){
        int i = 0;
        int j = 0;
        unordered_map<int,int> mp;
        int ans = 0;
        while(j<s.size()){
            mp[s[j]]++;
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            ans += (j-i+1);
            j++;
            }
        
    return ans;
    }
};