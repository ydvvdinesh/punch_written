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
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>front(n,0);
        //base condtion
        for(int j = 0; j<n; j++){
            front[j] = triangle[n-1][j];
        }
        //now we have to move from downward to 0,0
        for(int i = n-2; i>=0; i--){
            //moving to upside in row
            vector<int>curr(n,0);
            for(int j = i; j>=0; j--){ //creating the number which is equal to index
            int down = triangle[i][j] + front[j]; 
            int downright = triangle[i][j] + front[j+1];
            curr[j] = min(down, downright);
            }
            front = curr;
        }
        return front[0]; 
    }
};
