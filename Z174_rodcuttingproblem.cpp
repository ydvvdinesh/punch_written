//we boils down the question to collect the part of rod to form the length N , and you cannot go beyond the N , N is the maximum limit 
//total number of prices = total no of parts avaiable of rod
//target - create a road using the part so the price of the completed road is maximum among all
class Solution{
  public:
  //this function give us the maximum profit or value we get till reaching the index , to form length of N road
    int func(int ind, int N, vector<int>& price, vector<vector<int>>& dp){
        //base condition
        if(ind == 0){
            return N*price[0];
        }
        if(dp[ind][N] != -1){
            return dp[ind][N];
        }
        int notpick = 0 + func(ind-1, N,price, dp);
        int pick = INT_MIN;
        int rowindex = ind + 1; //ye lisye uskya hai jis pta chle ki hum n ke bhar toh nahi ja rahe hai a complete rod bnane ke check kar , and ha hum directly bhi likh skte the but , index 0 se hai toh lisliye ind +1 karna pdega
        if(rowindex <= N){
            pick = price[ind] + func(ind,N-rowindex,price,dp);
        } 
        return dp[ind][N] = max(notpick,pick);
    }

    int rodCutting(vector<int> price, int n) {
     vector<vector<int>> dp(n,vector<int>(n+1,-1));
     return func(n-1,n,price,dp);
    }
};
