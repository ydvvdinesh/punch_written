// dp same hi hai jada differnece nahi hai
class Solution {
   public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        // base case
        // har phase yaha index me alag weight ho skta hai jab hum usko ghte
        // laaye tab toh woh dhyan rakhna at index zero
        for (int weights = 0; weights <= W; weights++) {
            dp[0][weights] = (weights/ wt[0]) * val[0];
        }
        // now top up approach
        for (int ind = 1; ind < n; ind++) {
            for (int weight = 0; weight <= W; weight++) {
                int notpick = 0 + dp[ind - 1][weight];
                int pick = INT_MIN;
                // now hum tabhi tak weight pick kar skte hai jab tak hume
                // capacity of bag cross na ho
                if (wt[ind] <= weight) {
                    // now ye hi hai main khel yadi kiabhi bhi uestion mai bola
                    // jaye multiple steps yaha infintr time le skte ho that
                    // means same index ko baar baar lena hai jab tak conditon
                    // cross na krde
                    pick = val[ind] + dp[ind][weight - wt[ind]];
                }
                dp[ind][weight] = max(pick, notpick);
            }
        }
        return dp[n-1][W];
    }
};
