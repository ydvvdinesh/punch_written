// same hai part 3 jaise bus ek change usme at most 2 transaction kar skate the
// jisme at max k transaction kar skate hai do tarika solve karne ke , day , buy
// , capacity (jaise sell krenge capacity decrease hogi)
//  dusra hai day , transaction number , yadi transcation number even hai toh
//  buy krega , hum phele tarike se jayenge krenge dono but woh jadda intitutive
//  hai
class Solution {
   public:
    // we have to return maximum profit
    // buy ko zero or 1 mai khikyenge
   /* int func(int day, int buy, int cap, vector<int>& arr,
             vector<vector<vector<int>>>& dp) {
        int n = arr.size();
        // base case
        if (day == n || cap == 0) return 0;
        if (dp[day][buy][cap] != -1) {
            return dp[day][buy][cap];
        }
        int profit = 0;
        // what if it buy ,
        if (buy == 1) {
            // take or not take
            // take, toh hmare paise toh ghat  gaye na , func mai buy 1 hai
            // that`s means it has libraity to buy more if zero you cannot have
            // linberity to buy , first you have to buy then sell
            int a1 = -arr[day] + func(day + 1, 0, cap, arr, dp);
            int a2 = 0 + func(day + 1, 1, cap, arr, dp);
            profit = max(a1, a2);
        }
        // sell
        else {
            // selling or look for next price
            // sell kiya toh aache paise milenge
            int b1 = arr[day] + func(day + 1, 1, cap - 1, arr, dp);
            int b2 = 0 + func(day + 1, 0, cap, arr, dp);
            profit = max(b1, b2);
        }
        return profit;
    }*/
    // now tabluziation -hmesha base case phele ye leekhna hai ulta jayega jaise woh gya uske 
    int stockBuySell(vector<int> arr, int n, int k) {
        // why k+1 because 0,1,2,3,4, till......included k , total huwa k+1
        // tabluzaiotion n+1 leeneg as we know
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        // base case
        // ind n , baaki kuch bhi ho zero hi milenge
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 0; cap <= k; cap++) {
                dp[n][buy][cap] = 0;
            }
        }
        // yadi cap zero toh sab zero
        for (int day = 0; day < n; day++) {
            for (int buy = 0; buy <= 1; buy++) {
                dp[day][buy][0] = 0;
            }
        }
        // base case done , explore yaha do all stuff
        for (int day = n-1; day >= 0; day--) { // 0 to n-1 tak khel chlega 
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) { //zero phele hi nahi liya hai so one se shuru krenge
                    int profit = 0;
                    // what if it buy ,
                    if (buy == 1) {
                        // take or not take
                        // take, toh hmare paise toh ghat  gaye na , func mai
                        // buy 1 hai that`s means it has libraity to buy more if
                        // zero you cannot have linberity to buy , first you
                        // have to buy then sell
                        int a1 = -arr[day] + dp[day + 1][0][cap];
                        int a2 = 0 + dp[day+1][1][cap];
                        profit = max(a1, a2);
                    }
                    // sell
                    else {
                        // selling or look for next price
                        // sell kiya toh aache paise milenge
                        int b1 = arr[day] + dp[day+1][1][cap-1];
                        int b2 = 0 + dp[day + 1][0][cap];
                        profit = max(b1, b2);
                    }
                    dp[day][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};
