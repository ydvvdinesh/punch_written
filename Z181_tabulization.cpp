class Solution {
   public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int maxi  = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // dp mai degault value hi zero set ki hai so no worries ki we have to
        // do it
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // mactching
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0;
                }
            maxi = max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};
