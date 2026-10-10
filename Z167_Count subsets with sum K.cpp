//f(n-1,target) = till n-1 index how many of subset will give us the target 
//its combinstiof lec 14 and recurison of lec 7 , phele check kar rahe the and abhi bus count ksr rahe aur baai ek dum smae hai 
//as lectiure har count problem mai yadi hai toh return 1 and otherwise 0
class Solution{
	public:

    int func(int ind, int target, vector<int>&arr, vector<vector<int>>& dp){
        const int mod = 1e9 + 7;
        //basecase 
        if(target == 0) return 1;
        //ind , we are moving n-1 to 0, base case for index
        if(ind == 0){
            return (arr[ind] == target);
        }
        if(dp[ind][target] != -1){
           return dp[ind][target];
        }
        //explore all possiblies, we go with same conxept pick and not pick 
        //yadi pick nahi kiya toh we move to one previous index and target mai se kuch decrease toh hoga nai kyuki usko subsequnce mau count nahi kiya
        int notpick = func(ind-1,target,arr,dp);
        int pick = 0;
        if(arr[ind] <= target){
            pick = func(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target] = (pick + notpick) % mod;
    }

	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K+1,-1));
        return func(n-1,K,arr,dp);
	}
};
