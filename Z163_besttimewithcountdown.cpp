//exact like part 2 but only one difference with cool down
//cooldown - cannot buy on next day of sell, sell pe hi valid hoga only 
//toh hum sell ke next lenge toh sell ho jaye toh buy krne ind+2 , because we have librety to but 
class Solution {
public:

    int func(int ind, int buy, const vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        //base case
        //ind can become n + 1. So safer is, we can use the > sign 
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

    int maxProfit(const vector<int>& prices) {
        int n = prices.size();
        //n , then uske undr do hi column
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(0,1,prices,dp);
    }
};
