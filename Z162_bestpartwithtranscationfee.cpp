//same hai part two ki trayh bas ek minimial fee drecrease kardo har ek complete transaction  and hum multiple ttansaction kar skte hai 
//hum do jagah fees minus kar skte hai , yaha buy pe fees lgado yaha yaha selling pe utha do 
//har transaction pe fee kategi
class Solution{
public:
//day, buy (o mtln bahi kiya yadi 1 hai toh hoga)
    int func(int ind, int buy, vector<int>& arr, int fee, vector<vector<int>>& dp){
        int n = arr.size();
        //base condition
        if(ind == n){
            return 0;
        }
        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }
        int profit = 0;
        //if buy kiya
        if(buy == 1){
            //yadi buy huwa toh , hmari value toh ghati na , hmare paise toh gaye
            int a1 = -arr[ind] + func(ind+1,0,arr,fee,dp);
            int a2 = 0 + func(ind+1, 1, arr, fee,dp);
            profit = max(a1,a2);
        }
        //yadi sell karna hai toh , toh hume profit hoga hi 
        //hum selling pe fees consider krenge , aap buy ke time bhi kar skte ho
        else{
            int b1 = arr[ind] - fee + func(ind+1,1,arr,fee,dp);
            int b2 = 0 + func(ind+1,0,arr,fee,dp);
            profit = max(b1,b2);
        }
        return dp[ind][buy] = profit;
    }

    int stockBuySell(vector<int> arr, int n, int fee){
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return func(0,1,arr,fee,dp);//starting from index 0 and we assuming 1 se start hoga
    }
};
