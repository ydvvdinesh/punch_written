// we have to convert the string 1 into string 2 using three operations insert ,
// delete and replace , insert and selte waala toh hum just karke hi aaye hai

class Solution {
   public:
    int editDistance(string start, string target) {
        int n = start.size();
        int m = target.size();
        // same hai bus string me zero based indexing and , in comparing one
        // based ,
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // base case
        // indexing ki wajah se ab j hi aayega and usme i hi aayega , kyuki ab
        // last 0hi hoga phele -1 that ab 1 based indexing ka game chlega
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                //-1 isliye ab zero hi aayega bounde se bahar nahi jayega
                if (start[i - 1] == target[j - 1]) {
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                } else {
                    int insertion = 1 + dp[i][j - 1];
                    int deleteion = 1 + dp[i - 1][j];
                    int replacegame = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min(insertion, min(deleteion, replacegame));
                }
            }
        }
        return dp[n][m];
    }
};
