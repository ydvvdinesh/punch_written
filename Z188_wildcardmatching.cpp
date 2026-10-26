//dono yahi hai 
class Solution {
public:
    bool func(int i, int j, string str, string pat, vector<vector<int>>& dp){
        int n = str.size();
        int m = pat.size();
        //base case 
        if(i<0 && j<0){
            return true;
        }
        if(i<0 && j>=0){
            return false;
        }
        if(j<0 && i>=0){
            for(int ii = 0; ii<=j; ii++){
                if(pat[ii] != '*'){
                    return false;
                }
                return true;
            }
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //explore all posibility
        if(str[i] == pat[j] || str[i] == '?'){
            return dp[i][j] = func(i-1,j-1,str,pat,dp);
        }
         if (str[i] == '*'){
            return dp[i][j] = func(i-1,j,str,pat,dp) || func(i,j-1,str,pat,dp);
        }
        else{
            return dp[i][j] = false;
        }
    }

    bool wildCard(string str, string pat) {
        int n = str.size();
        int m = pat.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return func(n-1,m-1,str,pat,dp);
    }
};



class Solution {
public:
    bool wildCard(string str, string pat) {
        int n = str.size();
        int m = pat.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // base case
        dp[0][0] = true;

        // string is empty, pattern must contain only '*'
        for (int j = 1; j <= m; j++) {
            if (pat[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
            else {
                dp[0][j] = false;
            }
        }

        // fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (pat[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};

