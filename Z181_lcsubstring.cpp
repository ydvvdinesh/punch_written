// bilkul same hai sequence waala ke bus isme hume substr chayiey tih wih
// consecutive hoti hai , jab usme matching nahi mil rahi toh hum index ko rok
// ke dusre pe doond rahe the , kyuki subsequence bnane the , but  yadi isme
// nhai mile toh hum hume consecutive chayiye toh hum usme zero den denge
//and last me maximum return kar dena
class Solution {
   public:
    int func(int ind1, int ind2, string& str1, string& str2,
             vector<vector<int>>& dp) {
        // base case
        int n = str1.size();
        int m = str2.size();
        if (ind1 < 0 || ind2 < 0) return 0;

        // dp condition
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        // matched
        if (str1[ind1] == str2[ind2]) {
            return dp[ind1][ind2] =
                       1 + func(ind1 - 1, ind2 - 1, str1, str2, dp);
        }
        //e hi main khel hai 
        return dp[ind1][ind2] =0;
    }

    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i<n; i++){
          for(int j = 0; j<m; j++){
            maxi = max(maxi, func(i, j, str1, str2, dp));
          }
        }
        return maxi;
    }
};
