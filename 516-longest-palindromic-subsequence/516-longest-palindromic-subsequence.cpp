class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(s.begin(),s.end());
        string t=s;
        int n = s.size();
        vector<int> prev(n+1,0);
        for(int i = 1;i<=n;i++){
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++){
                if(a[i-1] == t[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};