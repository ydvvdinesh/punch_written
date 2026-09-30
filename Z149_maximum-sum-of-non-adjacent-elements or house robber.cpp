//recursion = we have to create subsequenece, constraint is given maximum sum of non adjacent element 
//so what we will do, we know how we create the subseuqnce , pick or not pick , in oick we are taking the that index, we have to process and in not pick , we not pick that index fro that particular sequence , 
//so yaha yadi pick krena hai toh adajcent nahi krna isliye hum n-2 pick krenge and jab pick nahi kar rahe iska matlab hai previous ko process krenge , kyuki jab usko pick nahi kar rahe toh previous toh aise hi pda 
// pick and non pick me se maximum lelo
/* recursion function
int func(int ind, vector<int>& nums){
        if(ind == 0) return nums[ind]; 
        if(ind<0) return 0; //negative index mai lafda na kare
        //current standing + previous to previous, yadi pick kar rahe hai toh constraint mai rhe ke pick krenge na, bola hai adjacent nahi karne hai 
        int pick = nums[ind] + func(ind-2, nums);
        //MOST IMPORTANT LINEEEEEEEEEEEEEEEEEEEEE
        //yadi pick nahi kar rahe toh subsequence mai gaya hi nahi toh zero + ab uske agle waala index process krenge 
        int nonpick = 0 + func(ind-1, nums);
        return max(pick, nonpick);
*/
// memorization - dp vector bna do + recursion (n) to base case tak jayega 
class Solution {
public:
    int func(int ind, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(ind == 0) return nums[ind]; 
        if(ind<0) return 0;
        //hume pure baare karne ki jaroort nahi hai hum uske store kar lenge, jiska -1 nahi hai mtalab alreay hum uski vlaue nikal chuke hai ab hum uska use krenge
        if(dp[ind] != -1){
            return dp[ind];
        }
        int pick = nums[ind] + func(ind-2, nums, dp);
        int nonpick = 0 + func(ind-1, nums, dp);
        return dp[ind] = max(pick, nonpick);
    }

    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        //recursion me n start hoga and zero tak jayega 
        return func(n-1,nums,dp);
    }
};
