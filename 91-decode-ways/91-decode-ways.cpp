class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return ans(0,s,dp);
    }
    int ans(int i,string s,vector<int>& dp){
        if(i == s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int res = 0;
        if(s[i] != '0') res+=ans(i+1,s,dp);
        if(i<s.size()-1 && (s[i]=='1' || (s[i]=='2'&& s[i+1] <'7'))) res+=ans(i+2,s,dp);
        return dp[i] = res;
    }
};