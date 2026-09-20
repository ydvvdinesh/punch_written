//recurision + memorization uss dp array thing 
//memorization - mai -1 intiliaze krte hai and phele phir bhartehai , tabluation mai sidha dp array bharte hai 

// saare dp array -1 honge jo value aayegi usse woh store krenge
class Solution {
public:

    int f(int n , vector<int>& dp){
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1 ) return dp[n];
        int firststep = f(n-1, dp);
        int twosteps = f(n-2, dp);
        return dp[n] = firststep + twosteps;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n, dp);
    }
};
