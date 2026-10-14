class Solution {
   public:
    int rodCutting(vector<int> price, int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        // base crase
        for (int i = 0; i <= n; i++) {
            dp[0][i] = i * price[0];
        }
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= n; target++) {
                int notpick = 0 + dp[ind - 1][target];
                int pick = INT_MIN;
                int rowindex =
                    ind +1;  // ye lisye uskya hai jis pta chle ki hum n ke bhar toh
                        // nahi ja rahe hai a complete rod bnane ke check kar ,
                        // and ha hum directly bhi likh skte the but , index 0
                        // se hai toh lisliye ind +1 karna pdega
                if (rowindex <= target) {
                    pick = price[ind] + dp[ind][target - rowindex];
                }
                 dp[ind][target] = max(notpick, pick);
            }
        }
        return dp[n-1][n];
    }
};
