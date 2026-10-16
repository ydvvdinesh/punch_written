// tbluzation
// basic isme ek corrdinste mappig karni hai so har jagah jo previous waala
// column dikhe waah +1 kr denge woh khud maap kar lenge
class Solution {
   public:
    int LIS(vector<int>& nums) {
        int n = nums.size();
        // base case ki koi jaroorat hai hi nahi , kyuki usko hum consider hi
        // nahi krenge
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int notpick = 0 + dp[ind + 1][prev + 1];
                int pick = INT_MIN;
                if (prev == -1 || nums[ind] > nums[prev]) {
                    pick = 1 + dp[ind + 1][ind+1]; // prev ke column mai hai isliye add kiya hai 1 otherwise no need
                }
                dp[ind][prev + 1] = max(notpick, pick);
            }
        }
        return dp[0][0];
    }
};
