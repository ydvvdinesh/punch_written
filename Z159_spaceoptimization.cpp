// ye || =same phele jaise hai maximum profi btana bus , isme hum kitni baar bhi stock ko buy aur sell kar skate hai bus dusra tabhi but kar skte hai jab phela sale ho  
class Solution{
public:
    int func(int ind, int buy, vector<int>& arr, vector<vector<int>>& dp){
        int n = arr.size();
         //0 to n recursion hoga
         //base condition
         if(ind == n){
            return 0;
         }

        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

         //yadi hum usko day ko but kar rahe hai , buy kar rahe toh 1 otherwise 0
         int profit = 0;
         if(buy == 1){
            //humne but karle par value badi hai and hum nuksaan kregi
            //-ve ktuki nuksaan hoga + ab hum but kar chuke hai so agle din/ index ab bu nahi krenge jab tak sell na ho isliye comma ke baad zero hoga
            int a1 = -arr[ind] + func(ind+1,0, arr, dp);
            //hum buy krenge but usko nahi hum usse agle ko dekhnge ki woh toh chhota hai ki nahi
            // jab liya hi nhai toh count nahi + 1 isliye aayega commna ke baad now it has librarity to but , upper waale me usko phele sell karna pdega 
            int a2 = 0 + func(ind+1,1, arr, dp);
            profit = max(a1,a2);
         }
         else{
            // now buy nahi krenge toh sell krenge 
            // yaha hum sell kar hai , hume piche waale se nda number mil gaya toh isliye hum sell kar rahe + cell karne ke baad uske pass libraity hogi buy karne ki 
            int b1 = arr[ind] + func(ind+1, 1,arr, dp);
            //hum piche le se chote mi rahe hai jo hume profit nahi denge , toh hum uss din sell nahi krnge and doonde jab tak hum usse chota nahi mil jis din hum sell kjar ske
            //sell huwa nahi toh buy nahi kar skte 
            int b2 = 0 + func(ind+1, 0, arr, dp);
            profit = max(b1,b2);
         }
        return dp[ind][buy] = profit;
    }

//space optimization 1d ke 2 array se hoga jayega piche waalo ki tayah hi hai, in this we replace dp array 
// jis aaray pe +1 , -1 woh aagepeeche waale hai , jispe kuch add nahi ho raha woh same hai 
    int stockBuySell(vector<int> arr, int n){
        vector<int> ahead(2,0); //size of 2 with initlization of 0
         vector<int> curr(2,0);
        //base case - zero nahi hoga n hoga kyuki ulta move kar rahe hai 
        //dp[ind][buy] 
        curr[0] = 0;
        curr[1] = 0;
        //yadi index zero toh chaye buy 1 ho zero dono ka answer zero aayega 
        for(int ind = n-1; ind>=0; ind--){
            //yaha toh one yaha zero 
            for(int buy = 0;buy<=1; buy++){
                int profit = 0;
         if(buy == 1){
            int a1 = -arr[ind] + ahead[0]; 
            int a2 = 0 + ahead[1];
            profit = max(a1,a2);
         }
         else{
            int b1 = arr[ind] + ahead[1];
            int b2 = 0 + ahead[0];
            profit = max(b1,b2);
         }
            curr[buy] = profit;
        }
        ahead = curr;
    }
        return curr[1]; //last waale index daal do kyuki  upper se bharte hi aayega haar baar
    }
};











