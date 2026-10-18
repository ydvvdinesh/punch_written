class Solution {
   public:
    int numberOfLIS(vector<int> nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        // jab do lis ki length same aaye toh hum count increase kar denge that
        // is the main idea
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                // yadi length har baar badi mil rahi hai toh , count same hi
                // rhega
                if (nums[ind] > nums[prev] && 1 + dp[prev] > dp[ind]) {
                    dp[ind] = 1 + dp[prev];
                    count[ind] = count[prev];
                }
                // yadi length same aarahi hai toh , count inrease hota jayega
                else if (nums[ind] > nums[prev] && dp[prev] + 1 == dp[ind]) {
                    count[ind] += count[prev];
                }
            }
            maxi = max(dp[ind], maxi);  // index which is maximum
        }
        int nos = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                nos += count[i];
            }
        }
        return nos;
    }
};
