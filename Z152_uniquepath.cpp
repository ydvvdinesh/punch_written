//memorization , no of path btane hai chaye 0,0 se start kro ya m-1, n-1 se same baath hai , path toh utne hi rhenge 
class Solution {
public:
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

        // ab hum do hi direction mai move kar skte hai , acc to question right and down but hum neeche se upper aarahe hai so left and upward krenge 
        //upper jayenge toh ek row kam hogi hi its precious hai 
        int up = func(i-1,j,dp);
        int down = func(i,j-1,dp);
        return dp[i][j] = up + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp);
    }
};
