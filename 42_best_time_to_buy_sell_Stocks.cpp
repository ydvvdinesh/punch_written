// buy krna hai ad minimal pricd pe and sell krdena hai maximum price pe , 
//logic = jo bhi day hai uske left me mini dondo and cost = selling day price - buying day price
//maximum and minimum ka track rakhna hai
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        int cost;
        for (int i = 0; i<n; i++){
            cost = prices[i] - mini; // ye bhai cost dekjh rhe hai , selling day - buying day
            profit = max(cost,profit); // maximum ka track rakh raha hai
            mini = min(mini,prices[i]);// ye mini ka
        }
        return profit;
    }
};
