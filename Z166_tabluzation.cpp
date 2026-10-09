//// bilkul same hai hai 1 waale ke bus thode changes hai 
//question - saare possible subset bnane hai, jin do sab set ka sum sabse minimum hai woh unn do subset mai hum parition krenge main array 
//approach - hum phele total sum nikalnenge then try and tested khelenge yadi s1(phela subsset) ko 0 t0 total sum mai kuch vhi maan lenge and s2(dusre parition ka sum) = totalsum - s1(sum of subset 1), jaise hi s1 and s2 ka sum aajayega toh unka unko minimum return kar dena  
class Solution {
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

    bool funcdp(int k, vector<int>& arr,
                vector<vector<int>>& dp) {
        int n = arr.size();

        for (int ind = 0; ind < n; ind++) {
            dp[ind][0] = true;
        }

        if (arr[0] <= k) {
            dp[0][arr[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool nottake = dp[ind - 1][target];

                bool take = false;
                if (arr[ind] <= target) {
                    take = dp[ind - 1][target - arr[ind]];
                }

                dp[ind][target] = take || nottake;
            }
        }

        return true;
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totalsum = 0;

        for (int i = 0; i < n; i++) {
            totalsum += stones[i];
        }

        int k = totalsum / 2;

        // DP table only up to half of total sum
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        funcdp(k, stones, dp);

        int s1 = 0;
        int s2 = 0;
        int mini = 1e9;

        for (int i = 0; i <= k; i++) {
            if (dp[n - 1][i]) {
                s1 = i;
                s2 = totalsum - s1;
                mini = min(mini, abs(s1 - s2));
            }
        }

        return mini;
    }
};
