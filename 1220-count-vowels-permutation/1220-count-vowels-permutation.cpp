class Solution {
public:
    int mod = 1e9+7;
    int countVowelPermutation(int n) {
        int mod = 1000000007;
	// dimensions of dp is nx5 as we have only 5 characters to compute
    long long dp[n][5];
	// initializing first row with 1 (when n = 1 , only a character is there)
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = ((dp[i - 1][1]) + (dp[i - 1][2]) + (dp[i - 1][4])) % mod;         // cases for a
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;                              // cases for e
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % mod;                              // cases for i
        dp[i][3] = (dp[i - 1][2]) % mod;                                             // cases for o
        dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % mod;                              // cases for u
    }
    long long ans = 0;
    for (int i = 0; i < 5; i++)
        ans = (ans + dp[n - 1][i]) % mod;
		// finally return the sum of all possibilities 
    return ans;
    }
};