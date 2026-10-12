//target sum is boils down to count the subset with parition sum 
//target is ultimately subtraction of sum of two subsets
//look as given in the question , assign the +/- to elements of the given array so their total we get as a target
//but when you think logically that is here we are taking taking groups of one , two three and asign them sign and add , that but they are become the total subset of positive - totall subset of negtive , , one subset of positive - one subset of negative , so it it same question become a slighlt change in langauge we gonna we use the same code here exact 

class Solution {
  public:
    int func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        //base condition
        const int mod = 1e9 + 7;
        if(ind == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || target == arr[0]) return 1;
            else{
                return 0;
            }
        }
        //base case done
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        int notpick = func(ind-1,target,arr,dp);
        int pick = 0;
        if(arr[ind]<=target){
            pick = func(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target] = (pick + notpick)%mod;
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalsum = 0;
        for(int i = 0; i<n;i++){
             totalsum += arr[i];
        }
        //total sum of the array
        if (totalsum < diff) return 0;
        if ((totalsum - diff) % 2 != 0) return 0;
        int s2 = (totalsum - diff)/2;
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return func(n-1,s2,arr,dp);
    }

  int targetSum(int n, int target, vector<int>& nums) {
    return countPartitions(n,target,nums);
 }
};
