//mempization give tle
//same hai part 3 jaise bus ek change usme at most 2 transaction kar skate the jisme at max k transaction kar skate hai 
//do tarika solve karne ke , day , buy , capacity (jaise sell krenge capacity decrease hogi)
// dusra hai day , transaction number , yadi transcation number even hai toh buy krega , hum phele tarike se jayenge krenge dono but woh jadda intitutive hai
class Solution{
public:

     // we have to return maximum profit 
     //buy ko zero or 1 mai khikyenge 
    int func(int day, int buy, int cap, vector<int> arr, vector<vector<vector<int>>> dp){
        int n = arr.size();
        //base case 
        if(day == n || cap ==0) return 0;
        if(dp[day][buy][cap] != -1){
            return dp[day][buy][cap];
        }
        int profit = 0;
        //what if it buy ,
        if(buy == 1){
            // take or not take 
            //take, toh hmare paise toh ghat  gaye na , func mai buy 1 hai that`s means it has libraity to buy more
            //if zero you cannot have linberity to buy , first you have to buy then sell
            int a1 = -arr[day] + func(day+1, 0, cap, arr,dp);
            int a2 = 0 + func(day+1, 1, cap, arr,dp);
            profit = max(a1,a2);
        }
        //sell
        else{
            //selling or look for next price
            //sell kiya toh aache paise milenge
            int b1 = arr[day] + func(day+1, 1, cap-1, arr,dp);
            int b2 = 0 + func(day+1, 0, cap, arr,dp);
            profit = max(b1,b2);
        }
        return profit;
    }

    int stockBuySell(vector<int> arr, int n, int k){
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,k,arr,dp);
    }
};
