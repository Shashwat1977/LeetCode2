class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int mx = 0;
        for(int i = 0;i<sentences.size();i++){
            int n = count(sentences[i].begin(),sentences[i].end(),' ');
            mx = max(mx,n+1);
        }
        return mx;
    }
};