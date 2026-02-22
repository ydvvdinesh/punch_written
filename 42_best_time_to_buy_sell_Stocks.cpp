// buy krna hai ad minimal pricd pe and sell krdena hai maximum price pe , 
//logic = jo bhi day hai uske left me mini dondo and cost = selling day price - buying day price
//maximum and minimum ka track rakhna hai
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost;
        int n = prices.size();
        int maxiprofit = 0;
        int mini = prices[0];
        for (int i = 0; i<n; i++){
            cost = prices[i]-mini;
            maxiprofit = max(cost,maxiprofit);//ye track record rakhte hai piche waale ka 
            mini = min(prices[i],mini);
        }
        return maxiprofit;
    }
};
