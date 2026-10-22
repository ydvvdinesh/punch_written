class Solution {
   public:
    int distinctSubsequences(string s, string t) {
        const int mod = 1e9 + 7;
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;  // t (subset) pura traverse ho chuka hai , kyui t s
                           // mai lies krta hai
        }
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 0;  // main set pura ho gaya and t rhgaya
        }
        // 1 based indexing for checking and for string 0 based
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i-1] == t[j-1]) { // why -1 due to -1 indexing 
                     dp[i][j] = ((long long)dp[i - 1][j - 1] +
                                       dp[i - 1][j]) %
                                      mod;
                } else {
                     dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
