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
    // ahead = dp[ind+1]
    vector<int> ahead(2, 0);
    // ahead2 = dp[ind+2]
    vector<int> ahead2(2, 0);
    // curr = dp[ind]
    vector<int> curr(2,0);
        //n , then uske undr do hi column, why n+2 kyuki uss curr position pe next store karna pd skta hai
        vector<vector<int>> dp(n+2,vector<int>(2,-1));
        curr[0] = 0;
        curr[1] =0;
        // for extra column
        curr[0] = 0;
        curr[1] = 0;
        // ulta recurisonka 
        for(int ind = n-1; ind>=0; ind--){
            for(int buy = 0; buy<=1; buy++){
                //buy and sell process 
        int profit = 0;
        if(buy ==1){
            int a1 = -prices[ind] + ahead[0];
            int a2 = 0 + ahead[1];
            profit = max(a1,a2);
        }
        else{//sell
        //yehi game plta jayega count down
            int b1 = prices[ind] + ahead2[1];
            int b2 = 0 + ahead[0];
            profit = max(b1,b2);
        }
        curr[buy] = profit;
            }
            ahead2 = ahead;
            ahead = curr;
        }
        return ahead[1];
    }
};
