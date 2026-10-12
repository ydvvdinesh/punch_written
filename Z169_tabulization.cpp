// tabulazation o to n-1 simple
class Solution {
   public:
    int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        // base case yadi ind zero hai aur value uss capcity ki range mah toh hi
        // sirf value return krega warna hmesha zero hi return larta rhega toh
        // saara w=weight array dekhne ki jarrooort nahi hai index zero and
        // weight vector ki condition daal hi di
        for (int weight = wt[0]; weight <= W; weight++) {
            dp[0][weight] = val[0];
        }
        for (int ind = 1; ind < n; ind++) {
            //this weight loop is runnign for the capacity of bag //har time chapacity byaegi ki ispe itni hai 
            for (int weight = 0; weight <= W; weight++) {
                int nonpick = 0 + dp[ind - 1][weight];
                int pick = INT_MIN;
                if (wt[ind] <= weight) {
                    pick =
                        val[ind] + dp[ind - 1][weight-wt[ind]];
                }
                dp[ind][weight] = max(pick, nonpick);
            }
        }
        return dp[n-1][W];
    }
};
