//bilukul same hai previous ki trah bus iss baar target total sum of array ka half ho jayega , baaki exact sme kyuki question ne bola hai exact 2 parts mai divide hoga , toh common sense hai na 
class Solution{
public:
    bool func(int ind, int target, vector<int>& arr,vector<vector<int>>& dp){
        //base condition
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target); //yadi last mai jo chayiye wohi mila that means hum jeet gaye hai 
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        //now explore all paths 
        bool nottake = func(ind-1,target,arr,dp);
        bool take = false;
        if(target >= arr[ind]){
            take = func(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target] = (take || nottake);
    }

    bool equalPartition(int n, vector<int> arr) { 
        int sum = 0;
        for(int i = 0; i<n; i++){
             sum += arr[i];
        }
        //ek most important point yadi sum negative hai that`s means usko proper divide kar nahi skte
        if(sum %2 == 1) return false;
        int k = sum/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        //k is our target 
        return func(n-1,k,arr,dp);
    }
};
