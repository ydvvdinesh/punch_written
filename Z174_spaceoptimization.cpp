class Solution {
   public:
    int rodCutting(vector<int> price, int n) {
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        // base case
        for (int i = 0; i <= n; i++) {
            prev[i] = i * price[0];
        }
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= n; target++) {
                int notpick = 0 + prev[target];
                int pick = INT_MIN;
                int rowindex =
                    ind +1;  // ye lisye uskya hai jis pta chle ki hum n ke bhar toh
                        // nahi ja rahe hai a complete rod bnane ke check kar ,
                        // and ha hum directly bhi likh skte the but , index 0
                        // se hai toh lisliye ind +1 karna pdega
                if (rowindex <= target) {
                    pick = price[ind] + curr[target - rowindex];
                }
                 curr[target] = max(notpick, pick);
            }
            prev = curr;
        }
        return prev[n];
    }
};
