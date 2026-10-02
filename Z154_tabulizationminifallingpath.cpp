class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // base case 
        for(int j =0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }
        //now use the traversal thing and woh j waala base case dhyan rakhna
        //already base case fill ho chuka hai 
        for(int i = 1; i<n; i++){
            for(int j =0; j<m; j++){
                int up =0;
                int upleft = 1e9; 
                int upright = 1e9;
                up = matrix[i][j] + dp[i-1][j];
                if(j>0){
                 upleft = matrix[i][j] + dp[i-1][j-1];
                }
                if(j+1<m){
                 upright = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min(up, min(upleft, upright));
            }
        }
        
        // har cell ki call karna uss row toh ab saabka minimum doondennge
        int mini = INT_MAX;
        for(int j =0;j<m;j++){
             mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};
