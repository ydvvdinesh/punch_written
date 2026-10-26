// bottoms down , kyuki recurison bottom tha n a
class Solution {
   public:
    int matrixMultiplication(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // base case
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        // explore all parition
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j < n; j++) {
                int mini = 1e9;
                for (int k = i; k < j; k++) {
                    int operation = (nums[i - 1] * nums[k] * nums[j]) +
                                    dp[i][k] +
                                    dp[k + 1][j];
                    mini = min(operation, mini);
                }
                 dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};
