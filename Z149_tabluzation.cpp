//tabluzation 0 to n jaana , without using recursion , same hi hai base recursion case ko convert karna hota hai 
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        dp[0] = nums[0]; //if ind = 0 return that number same like recursion,
        // yadi negative hai toh zero dhyan dusra base case
        for(int i = 1; i<n;i++){
            // but if i = 1 then we get negative index so prevent from it we putting one condition
 //yadi i one hai toh
        int pick = nums[i];
        if(i>1){
                 pick = nums[i] + dp[i-2];
            }
            int nonpick = 0 + dp[i-1];
            dp[i] = max(pick, nonpick);
        }
        /* The last element of the dp array
        will contain the maximum sum*/
        return dp[n-1];
    }
};
