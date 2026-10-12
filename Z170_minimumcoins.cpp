                
//question kuch paise diye honge , like coins of 1 , 2, 5, 10, but isme woh 1 ko 2 ko 3 ko4 ko 5 kisiko bhi bhi currency declare kar skte hai uss currency se hume given amount / target bnana hai , and iss way mai bnana hai jis se minimum no of coins use ho 

class Solution{
	public:
    //this fumction tells till ind how many minimum coins we used to make the amount
    int func(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        int n = coins.size();
        //base case 
        if(ind == 0){
            if(target % coins[ind] == 0) return target/coins[ind];
            else{
                return 1e9;
            }
        }
        //dp condition
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        //yadi pick nahi kiya toh next ind pe jayenge and target mai kuch contribute nahi kiya toh utna hi rhega and minimum coins we used is 0, koi pick hi nahi kiya 
        int notpick = 0 + func(ind-1,target,coins,dp);
        //yadi pick kiya toh phele dekhenege amount se jada toh nahi ja raha na and second thing is iss question mai ye nahi bola hai ki value/ya curreny ko ek baar lena , they say ek coin/yaaha value ko infite times le skte ho, bus they demanded minimum koi , ab kabhi kabhi in dp yadi ye diya hai ki infinite ./ multiple use toh ussi index pe baar baar chalna hai jab tak wrong na ho jaye which yadi coin bda hai target se kuch nahi phir 
        //and jab lenge toh usko 1 ghinenge , pick krenge toh 1 ginenge
        int pick = 1e9;
        if(coins[ind] <= target){
            pick = 1 + func(ind,target - coins[ind],coins,dp);
        }
        return dp[ind][target] = min(pick,notpick);
    }

	int MinimumCoins(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = func(n-1,amount,coins,dp);
        //yadi no of minimum coins jada hogay 1e9 e toh hum bol denge nahi mila and we return -1
        if(ans >= 1e9) return -1;
        return ans;
    }
};
