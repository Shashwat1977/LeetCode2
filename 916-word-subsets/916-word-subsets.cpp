class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size();
        int m = words2.size();
        vector<vector<int>> vec1(n,vector<int> (26,0));
        vector<vector<int>> vec2(m,vector<int> (26,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<words1[i].size();j++){
                vec1[i][words1[i][j] - 'a']++;
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<words2[i].size();j++){
                vec2[i][words2[i][j] - 'a']++;
            }
        }
        vector<int> mx(26,0);
        for(int i = 0;i<26;i++){
            for(int j = 0;j<words2.size();j++){
                mx[i] = max(mx[i],vec2[j][i]);
            }
        }
        vector<string> ans;
        
        for(int i = 0;i<vec1.size();i++){
            bool flag = true;
            for(int j = 0;j<26;j++){
                if(mx[j]>vec1[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(words1[i]);
        }
        return ans;
    }
};