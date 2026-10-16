//space optimization - only ek hi working hai 
class Solution {
   public:
    int LIS(vector<int>& nums) {
        int n = nums.size();
        // base case ki koi jaroorat hai hi nahi , kyuki usko hum consider hi
        // nahi krenge
        vector<int> ahead(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int notpick = 0 + ahead[prev + 1];
                int pick = INT_MIN;
                if (prev == -1 || nums[ind] > nums[prev]) {
                    pick = 1 + ahead[ind+1]; // prev ke column mai hai isliye add kiya hai 1 otherwise no need
                }
                curr[prev + 1] = max(notpick, pick);
            }
            ahead = curr;
        }
        return ahead[0];
    }
};
