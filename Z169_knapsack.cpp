//target find the maximum value at any how
//eay one , bus rember one thing , we are going with the same approach pick it or not pick it , if we picking up then we have to think about the capcity of bag, that is represents by W, yes baaki same hai dp 14 ki trh usme true false return kar na isliye koi value add nahi kar rahe the but abhi maximum value return karni hai toh add  kar rahe hai 
class Solution{
    public:
        //recursion + memo
        int func(int ind, vector<int>& wt, vector<int>& val, int n, int W, vector<vector<int>>& dp){
            //base case 
            // n-1 se chale to last me 0 pe hi rukege
            if(ind == 0){
                if(wt[ind] <= W) return val[0];
                else{
                    return 0;
                }
            }
            
            if(dp[ind][W] != -1){
                return dp[ind][W];
            }
            //value return karni hai isliye add , kar rahe hai in future kabhi dp me answer mai value return karne ko bole toh value add hogi hi hoga
            //jab kuch pick hi nahi kar rahe toh bag ki capacity toh same hi rhegi 
            int nonpick = 0 + func(ind-1, wt, val,n,W,dp);
            int pick = INT_MIN;
            //yadi raha toh capacity check kro bag ki usme jayega ki nahi and yadi jayega tabhi leneg and lenege toh capacity decrease ho jayegi
            //wt of that index jisko le rahe hai if it lies under the capacity in bag , utna le ske to pick up
            if(wt[ind] <= W){
                pick = val[ind] + func(ind-1,wt,val,n,W-wt[ind],dp);
            }
            return dp[ind][W] = max(pick,nonpick);
        }

        int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) {
             vector<vector<int>> dp(n,vector<int>(W+1,-1));
             return func(n-1,wt,val,n,W,dp);
        }
};
