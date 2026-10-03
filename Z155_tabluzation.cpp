//sab dp ki trah isme nahi jayenge ki upper se shuru kiya and neeche khatam kiya 
class Solution {
public:
    /*int func(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
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
    }*/
    //tabulaation is going from n-1 to 0, recursion ke humesha ulta hogi , like thumb rulke 
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        //base condtion
        for(int j = 0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        //now we have to move from downward to 0,0
        for(int i = n-2; i>=0; i--){
            //moving to upside in row
            for(int j = i; j>=0; j--){ //creating the number which is equal to index
            int down = triangle[i][j] + dp[i+1][j]; 
            int downright = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, downright);
            }
        }
        return dp[0][0]; //ulte isliye 00, other wise n-1 and m-1 hoga 
    }
};
