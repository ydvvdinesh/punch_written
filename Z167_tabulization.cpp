// f(n-1,target) = till n-1 index how many of subset will give us the target
// its combinstiof lec 14 and recurison of lec 7 , phele check kar rahe the and
// abhi bus count ksr rahe aur baai ek dum smae hai as lectiure har count
// problem mai yadi hai toh return 1 and otherwise 0
class Solution {
   public:

    int perfectSum(vector<int>& arr, int K) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));
        // condition
        // yadi sum zero hai toh un sab jagahoo pe zero hi hoga
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        // yadi ind zero hai toh
        if (arr[0] <= K) {
            dp[0][arr[0]] = 1;
        }
        // now jitne parameter utne hi nested loop
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= K; target++) {
                int notpick = dp[ind - 1][target];
                int pick = 0;
                if (arr[ind] <= target) {
                    pick = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = (pick + notpick) % mod;
            }
        }
        return dp[n - 1][K];
    }
};
