class Solution {
   public:
    // palindrome
    bool pali(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; i--) {
            // explore all possibiilty
            int mini = 1e9;
            for (int j = i; j < n; j++) {
                // yadi jisme gaye and woh palindrome hai toh ek parition udr
                // and next se start kro
                if (pali(i, j, s) == true) {
                    int cost = 1 + dp[j + 1];
                    mini = min(cost, mini);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};
