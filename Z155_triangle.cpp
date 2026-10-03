//sab dp ki trah isme nahi jayenge ki upper se shuru kiya and neeche khatam kiya 
class Solution {
public:
    int func(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int n =triangle.size();
        //base we are starting from the upper, woh fix hai waha se  
        if(i == n-1){
            return triangle[n-1][j];
        }
        // if already there 
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //go down , current + call for the down one 
        int down = triangle[i][j] + func(i+1, j, triangle, dp); 
        int downright = triangle[i][j] + func(i+1, j+1, triangle, dp); 
        return dp[i][j] = min(down, downright);
    }
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return func(0,0,triangle,dp);
    }
};
