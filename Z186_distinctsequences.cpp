class Solution {
   public:
   const int mod = 1e9 + 7;
   //functions tells us the no of distinct subsequence of t[0....j] into s[0.....i]
   int func(int i, int j, string s, string t, vector<vector<int>>& dp){
    //base case 
    //yadi jisko doond rahe hai bade waale woh complete ho chuka then we return 1 otherwise 2 
    
    if(j<0){
        return 1;
    }
    if(i<0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    //explore the possibilty 
    if(s[i] == t[j]){
        //yadi same hai toh next me move krenge and remeber the isme distinct hai toh phele g ko chod ke hum dura g bhi le skte hai isliye piche move krenge 
        return dp[i][j] =  ((long long)func(i-1,j-1,s,t,dp) + func(i-1,j,s,t,dp)) % mod;
    }
    else{
    return dp[i][j] = func(i-1,j,s,t,dp);
    }
   }
    int distinctSubsequences(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return func(n-1,m-1,s,t,dp);
    }
};
