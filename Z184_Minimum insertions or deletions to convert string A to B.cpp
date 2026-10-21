class Solution {
   public:
   // tabluxation
   int lcs(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    //base case ki koi zaroorat nahi hai kyuki initliaze hi x=zero ki hai 
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            //matched
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            //not matched
            else{
                dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
   }

    int minOperations(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        return (n+m - 2*lcs(str1, str2));
    }
};
