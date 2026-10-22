//supersequemce = str1 + str2, is question mai ek catch hai shortest return karna hai and simple way - jo common hai usko ek baar likheenge , mtlb common nikal denge 
//so very easy hailength nikal , jitne common hai woh lcs bta dega and totoal me se lc waale nikal denge toh answer , aajayenge
//int length = m +n -lcs
// print ke liye lcs waali dp se nikal lenge
//len nikalna bahut aasan hai 
class Solution {
   public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //base case intilize karne ki koi jaroort nahi kyukki alreadyhum zero put kiya hai
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        //yaha tak dp matrix full ho gayi hai and abhi hum last se traverse krenge , and same dono charcter same rhega toh answer mai store krenge and jab different rhega toh jo boundary off gaya usko answer mai store krenge and yadi upper gaya , mtlb upper waali row mai toh neche waala piss off hoga and usko phir answer mai store kr lenge
        //jab back mai move krenge toh jo bda hoga phele usme hayenge and yadi same hai toh kisipe bhi jaoo chlega 
        int i = n;
        int j = m;
        string ans = "";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1]; //yadi same hai toh kisi waale ko bhi le lenge
                //then move to last n=one jaa se woh aaya hai
                i--;
                j--;
            }
            //jo number bhi bada hoga pele usme jayega , then uss chote mai 
            else if(dp[i-1][j]>dp[i][j-1]){
               ans += str1[i-1]; 
               i--;
            }
            else{
                 ans += str2[j-1]; 
                 j--;
            }
        }
        //still last me bcha kuch bhi 
        while(i>0){
             ans += str1[i-1];
               i--; 
        }
        
        while(j>0){
              ans += str2[j-1]; 
               j--; 
        }
         // Backtracking mein reverse order mein string bani hai.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
