//tabluzation - it means you are doing from 0 to n using the vector isme koi recursion function nahi bnana sab ussi mai ho jayega
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n+1, -1);
        int ss = INT_MAX;
        dp[0] = 0;
        for(int i = 1; i<n; i++){
            int fs = dp[i-1] + abs(heights[i] - heights[i - 1]);
            if(i>1){
                ss = dp[i-2] + abs(heights[i] - heights[i - 2]);
            }
            dp[i] = min(fs,ss);
        }
        return dp[n-1];
    }
};
