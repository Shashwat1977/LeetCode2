class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp;
        for(int i  = 0;i<p.size();i++){
            mp[p[i]]++;
        }
        int k = p.size();
        int cnt = 0;
        vector<int> temp;
        int count = mp.size();int i = 0;int j = 0;
        while(j<s.size()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0){
                    count--;
                }
            }
            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                if(count == 0){
                    cnt++;
                    temp.push_back(i);
                }
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1) count++;
                    }
                
                i++;
                j++;
            }
        }
        return temp;
    }
};