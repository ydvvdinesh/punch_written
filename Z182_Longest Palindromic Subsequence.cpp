//ek dum easy panlindrome means yadi normal string ko reverse kardo woh toh bhi same hi dikhe , so for subswquwnce , reverse karke umne common nikal ne and jitna ho skte length badi hai , unn dono me common hogi woh khud plaindrome ho jayega 
//pura lcs hai bus ghooma ke khelna hai 

class Solution{
    public: 
    //tabulization
        int lcs (string str, string mtr){
            int n = str.size();
            int m = mtr.size();
            vector<vector<int>> dp(n+1,vector<int>(m+1,0));
            //dfault zero hai toh base case likhna koi jaroorat nahi hai 
            for(int i = 1;i<=n;i++){
                for(int j = 1; j<=m;j++){
                    //matched
                    if(str[i-1] == mtr[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    //unmatched
                    else{
                    dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
            return dp[n][m];
        }

        int longestPalinSubseq(string s) {
           string t = s;
           reverse(t.begin(),t.end());
           return lcs(s,t);
        }
};
