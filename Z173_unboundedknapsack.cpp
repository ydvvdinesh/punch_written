//memorization
class Solution {
   public:
    int func(int ind, int W, int n,vector<int>& wt, vector<int>& val, vector<vector<int>>& dp){
        //base case 
        // if we are not last inddex to hum kitini baar usko le skte hai capacity/wt[ind], capacity by weight of that index
        //total value kitni milegi = jitna baar liya * ek baar ki value
        if(ind == 0){
            return (W/wt[ind])*val[ind];
        }

        //dp condition
        if(dp[ind][W] != -1){
            return dp[ind][W];
        }
        //if we are not picking 
        int notpick = 0 + func(ind-1,W,n,wt,val,dp);
        int pick = INT_MIN;
        //now hum tabhi tak weight pick kar skte hai jab tak hume capacity of bag cross na ho 
        if(wt[ind] <= W){
            //now ye hi hai main khel yadi kiabhi bhi uestion mai bola jaye multiple steps yaha infintr time le skte ho that means same index ko baar baar lena hai jab tak conditon cross na krde 
            pick = val[ind] + func(ind,W-wt[ind],n,wt,val,dp);
        }
        return dp[ind][W] = max(pick,notpick);
    }

    int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return func(n-1,W,n,wt,val,dp);
    }
};
