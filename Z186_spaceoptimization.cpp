//thoda alag hai ek baar dekh lena 

  
class Solution {
   public:
    int distinctSubsequences(string s, string t) {
        const int mod = 1e9 + 7;
        int n = s.size();
        int m = t.size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);

        // Base case
        prev[0] = 1;

        // 1-based DP indexing, strings remain 0-based
        for (int i = 1; i <= n; i++) {
            curr[0] = 1;

            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = ((long long)prev[j - 1]
                               + prev[j]) % mod;
                } else {
                    curr[j] = prev[j];
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};
