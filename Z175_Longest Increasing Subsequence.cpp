//brute force this give us the runtime error 
//problem - find the length of longest increasing subsequence , increasing subsequence means , in every subsequence we are making from the parent array every next index is greater then previous 
//approach - we have two option can we take that into our subsequence or we can`t take in our subsequence 
// if we take it , then we compare with last / prev element kya woh previous se bda hai toh hi lenge and , isliye hum prev ko bhi store krenge , nahi compare nahi kar payenge, starting mai prev_index ko -1 maanege, damn bro 
// f(i,prev_index) - length of longest increaseing subseuence starts from index if
//toh jaise jaise dsure index pe jayenge woh unki lengeth denge
//bus ek slight change hai that is jab dp declare kar tab prev_index ki cooordinate mapping karke usko 0 to n , krna kuyuki hum -1 ka size declare nahi kar skte hai 
class Solution {
public:
    int func(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        // 0 to n ja rahe hai so out of index n ki traf hoga 
        if(ind == n) return 0;
        //cooordinate 0 to n karne ke liye dp index mai add kiya hai 
        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }
        //jab pick nahi krenge toh utni hi length rhegiu and jaise hi pick karenge toh length 1 se increase hogi because we are taking one element into subsequence 
        int notpick  = 0 + func(ind + 1, prev,nums,dp);
        int pick = INT_MIN;
        if(prev == -1 || nums[ind]>nums[prev]){
            pick = 1 + func(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1] = max(notpick , pick);
    }
    int LIS(vector<int>& nums) {
      int n = nums.size();
       if (n == 0) return 0;
      vector<vector<int>> dp(n, vector<int>(n+1,-1));
      return func(0,-1,nums,dp);
    }    
};
