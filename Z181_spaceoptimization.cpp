class Solution {
   public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int maxi = 0;
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        // dp mai degault value hi zero set ki hai so no worries ki we have to
        // do it
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // mactching
                if (str1[i - 1] == str2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = 0;
                }
                maxi = max(curr[j],maxi);
            }
            prev = curr;
        }
        return maxi;
    }
};
