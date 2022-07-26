class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto it:arr1){
            mp[it]++;
        }
        vector<int> ans;
        for(int i = 0;i<arr2.size();i++){
            int val = arr2[i];
            int freq = mp[val];
            for(int j = 1;j<=freq;j++){
                ans.push_back(val);
                mp[val]--;
                if(mp[val] == 0){
                    mp.erase(val);
                }
            }
        }
        for(auto it:mp){
            for(int i = 1;i<=it.second;i++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};