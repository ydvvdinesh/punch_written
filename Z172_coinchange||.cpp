//same hai bus count the nof ways and eact same hai count waala , ke bus ek change ki yadi infinte time le ske toh , jab wrong na ho jaye itne leta rhega 
//mixture of counts + minimumc coins |
class Solution {
public:
int func(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        int n = coins.size();
        //base case 
        if (ind == 0) {
            if (target % coins[0] == 0) return 1;
            return 0;
        }

        //dp condition
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        //yadi pick nahi kiya toh next ind pe jayenge and target mai kuch contribute nahi kiya toh utna hi rhega and minimum coins we used is 0, koi pick hi nahi kiya 
        int notpick = 0 + func(ind-1,target,coins,dp);
        //yadi pick kiya toh phele dekhenege amount se jada toh nahi ja raha na and second thing is iss question mai ye nahi bola hai ki value/ya curreny ko ek baar lena , they say ek coin/yaaha value ko infite times le skte ho, bus they demanded minimum koi , ab kabhi kabhi in dp yadi ye diya hai ki infinite ./ multiple use toh ussi index pe baar baar chalna hai jab tak wrong na ho jaye which yadi coin bda hai target se kuch nahi phir 
        //and jab lenge toh usko 1 ghinenge , pick krenge toh 1 ginenge
        int pick = 0;
        if(coins[ind] <= target){
            pick = func(ind,target - coins[ind],coins,dp);
        }
        return dp[ind][target] = (pick+notpick);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = func(n-1,amount,coins,dp);
        return ans;
    }
};
