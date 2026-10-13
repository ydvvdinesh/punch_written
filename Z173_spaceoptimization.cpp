// dp same hi hai jada differnece nahi hai
class Solution {
   public:
    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<int> prev(W + 1, 0);
        vector<int> curr(W + 1, 0);
        // base case
        // har phase yaha index me alag weight ho skta hai jab hum usko ghte
        // laaye tab toh woh dhyan rakhna at index zero
        for (int weights = 0; weights <= W; weights++) {
            prev[weights] = (weights/ wt[0]) * val[0];
        }
        // now top up approach
        for (int ind = 1; ind < n; ind++) {
            for (int weight = 0; weight <= W; weight++) {
                int notpick = 0 + prev[weight];
                int pick = INT_MIN;
                // now hum tabhi tak weight pick kar skte hai jab tak hume
                // capacity of bag cross na ho
                if (wt[ind] <= weight) {
                    // now ye hi hai main khel yadi kiabhi bhi uestion mai bola
                    // jaye multiple steps yaha infintr time le skte ho that
                    // means same index ko baar baar lena hai jab tak conditon
                    // cross na krde
                    pick = val[ind] + curr[weight - wt[ind]];
                }
                curr[weight] = max(pick, notpick);
            }
            prev = curr;
        }
        return prev[W];
    }
};
