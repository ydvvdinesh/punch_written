class Solution {
public:
int func(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        //base case
        
        if(ind >=n) return 0;
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        //buy and sell process 
        int profit = 0;
        if(buy ==1){
            int a1 = -prices[ind] + func(ind+1,0,prices,dp);
            int a2 = 0 + func(ind+1,1,prices,dp);
            profit = max(a1,a2);
        }
        else{//sell
        //yehi game plta jayega count down
            int b1 = prices[ind] + func(ind+2,1,prices,dp);
            int b2 = 0 + func(ind +1, 0,prices,dp);
            profit = max(b1,b2);
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //n , then uske undr do hi column, why n+2 kyuki uss curr position pe next store karna pd skta hai
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        dp[n][0] = 0;
        dp[n][1] =0;
        // for extra column
        dp[n+1][0] = 0;
        dp[n+1][1] = 0;
        // ulta recurisonka 
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                //buy and sell process 
        int profit = 0;
        if(buy ==1){
            int a1 = -prices[ind] + dp[ind+1][0];
            int a2 = 0 + dp[ind+1][1];
            profit = max(a1,a2);
        }
        else{//sell
        //yehi game plta jayega count down
            int b1 = prices[ind] + dp[ind+2][1];
            int b2 = 0 + dp[ind+1][0];
            profit = max(b1,b2);
        }
        dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
