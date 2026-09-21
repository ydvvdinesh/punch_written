//tablutaion - dono hi dp index ko bharte hai but memoriztion n to 0 index tak bharta aata hai and tabluation 0 to n tak bharta jaata hai
class Solution {
public:
    int f(int n){
        //Declare dp array of size n+1
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n) {

        return f(n);
    }
};
