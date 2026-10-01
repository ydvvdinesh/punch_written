//tabulation 
class Solution {
public:
//memorization , no of path btane hai chaye 0,0 se start kro ya m-1, n-1 se same baath hai , path toh utne hi rhenge 
    int func(int i, int j, vector<vector<int>>& dp){
        //base condtion
        if(i == 0 && j == 0){
            return 1;
        }
        // if negative index aaya 
        if(i<0 || j<0){
            return 0;
        }
        //for memorization condition
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // ab hum do hi direction mai move kar skte hai , acc to question right and left but hum neeche se upper aarahe hai so left and upward krenge 
        //upper jayenge toh ek row kam hogi hi its precious hai 
        int up = func(i-1,j,dp);
        int left = func(i,j-1,dp);
        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                //base condition 
                if(i==0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                //negtive ki toh tension hai hi nahi positive se start kiya hai
                //up + left 
                int up = 0;
                int left = 0;

                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    left = dp[i][j-1];
                }

                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
};
