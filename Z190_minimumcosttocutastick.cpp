class Solution {
   public:
    int func(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        int n = cuts.size();
        // base case
        if (i > j) return 0;
        // dp condition
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // explore all cuts , kaha kaha karna
        int mini = 1e9;
        for (int ind = i; ind <= j; ind++) {
            int steps = (cuts[j + 1] - cuts[i - 1]) +
                        func(i, ind - 1, cuts, dp) + func(ind + 1, j, cuts, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, -1));
        return func(1, c-2, cuts, dp);
    }
};
