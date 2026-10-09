// bilkul same hai hai 1 waale ke bus thode changes hai 
//question - saare possible subset bnane hai, jin do sab set ka sum sabse minimum hai woh unn do subset mai hum parition krenge main array 
//approach - hum phele total sum nikalnenge then try and tested khelenge yadi s1(phela subsset) ko 0 t0 total sum mai kuch vhi maan lenge and s2(dusre parition ka sum) = totalsum - s1(sum of subset 1), jaise hi s1 and s2 ka sum aajayega toh unka unko minimum return kar dena  
class Solution{
  public:
    bool func(int ind, int target, vector<int>&arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind ==0) return (arr[0] == target);
        //explore all stuff
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        bool nottake = func(ind-1,target,arr,dp);
        bool take = false;
        if(arr[ind] <= target){
            take = func(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target] = (take || nottake);
    }
    
	int minDifference(vector<int>&arr, int n)  { 
        int totalsum = 0;
        for(int i =0; i<n; i++){
            totalsum += arr[i];
        }
        vector<vector<int>> dp(n, vector<int>(totalsum+1, -1));
        // 0 to total sum
        int s1 =0; //sum of elements of subset 1 
        int s2 = 0; // sum of elements of subset 2
        int mini = 1e9;
        for(int i = 0; i<=totalsum; i++){
            //yadi possible hai toh
            if(func(n-1,i,arr,dp) == true){ // baar 0 to totaksum mai se ek ko target maanke karneg
                s1= i;
                s2= totalsum - s1;
                mini = min(mini, abs(s1-s2));
            }
        }
        return mini;
	} 
};
