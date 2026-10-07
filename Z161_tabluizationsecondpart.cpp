// mempization give tle
// same hai part 3 jaise bus ek change usme at most 2 transaction kar skate the
// jisme at max k transaction kar skate hai do tarika solve karne ke , day , buy
// , capacity (jaise sell krenge capacity decrease hogi)
//  dusra hai day , transaction number , yadi transcation number even hai toh
//  buy krega , hum phele tarike se jayenge krenge dono but woh jadda intitutive
//  hai
class Solution {
    // transaction number waale se , transaction number - transno
    // isme ye concept hota hai yadi buy huwa toh bhiek transcation ginhni jaye
    // and yadi sell huwa toh bhi hum cap me n-1 to zero tak aarahe hai phir
    // zero pe check kar rahe the but ism0 to k jayegnge in transaction only
    // recursion vaise hi hoga jase ho raha hai
    /*imp point -  // transno = number of BUY/SELL actions performed
    //
    // even transno -> BUY
    // odd transno  -> SELL
    //
    // 1 complete transaction = BUY + SELL
    // so k transactions = 2*k actions
    */
   public:
    int stockBuySell(vector<int> arr, int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(2 * k+1, -1));
        // base case
        // yadi index one hai n hai toh , baaki zero check hi mat karooo
        for (int transno = 0; transno <= 2*k; transno++) {
            dp[n][transno] = 0;
        }
        // yadi transno number k hai toh zero phir kuch bhi
        for (int day = 0; day < n; day++) {
            dp[day][2 * k] = 0;
        }
        // ab jitni number mai express kiya hai utne mai hi loop chlati hai
        for (int day = n - 1; day >= 0; day--) {
            for (int transno = 0; transno < 2 * k; transno++) { //base case ko count nahi karna bro
                int profit = 0;
                // what if it buy ,
                if (transno % 2 == 0) {  // yadi even hai toh buy mana jayega
                    // take or not take
                    // take, toh hmare paise toh ghat  gaye na , func mai buy 1
                    // hai that`s means it has libraity to buy more if zero you
                    // cannot have linberity to buy , first you have to buy then
                    // sell
                    int a1 = -arr[day] + dp[day + 1][transno + 1];
                    int a2 = 0 + dp[day + 1][transno];
                    profit = max(a1, a2);
                }
                // sell
                else {
                    // selling or look for next price
                    // sell kiya toh aache paise milenge
                    int b1 = arr[day] + dp[day + 1][transno + 1];
                    int b2 = 0 + dp[day + 1][transno];
                    profit = max(b1, b2);
                }
                dp[day][transno] = profit;
            }
        }
        return dp[0][0];
    }
};
