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
    }  // function that gives minimum no oarition through we get the pslindrome
       // string
    int func(int i, string s, vector<int>& dp) {
        int n = s.size();
        if (i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        // explore all possibiilty
        int mini = 1e9;
        for (int j = i; j < n; j++) {
            // yadi jisme gaye and woh palindrome hai toh ek parition udr and
            // next se start kro
            if (pali(i, j, s) == true) {
                int cost = 1 + func(j + 1, s, dp);
                mini = min(cost, mini);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return func(0, s, dp) - 1;
    }
};
