//recursive solution , n index se 0 index tak jaata hai
//memorize - recursive + use of the dp vector
class Solution {
public:
    int f(int n, vector<int>& heights, vector<int>& dp){
        if(n == 0) return 0;
        if(dp[n] != -1){
            return dp[n];
        }
        int right = INT_MAX;
        //left and right recursion mai hume term rakhi hai , left me hum 1 index chlenege and right me hum 2 index chlenge 
        //isme saath saath energy bhi dekhni hai 
        int left = f(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
        if(n>1){
            right = f(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
        }
        return dp[n] = min(left, right);
    }
    
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n+1, -1);
        return f(n-1, heights,dp);
    }
};
