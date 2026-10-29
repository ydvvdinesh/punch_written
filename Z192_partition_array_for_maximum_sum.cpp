//same like palindrome partionaing 
class Solution {
public:
    int func(int ind, vector<int>& arr, int k, vector<int>& dp){
        int n = arr.size();
        if(ind == n) return 0;
        int maxi = INT_MIN;
        int maxians = INT_MIN;
        int len = 0; // kitne tak gaye
        if(dp[ind] != -1){
            return dp[ind];
        }
        for(int j = ind; j< min(n, ind+ k); j++){
            len++; //har baar count hoiga uska 
            maxi = max(maxi, arr[j]); //maximum number ka count liya jayega , jo jitna maximum hai usse parition mai utni baar hi use multiply krwa denge 
            int sum = len*maxi + func(j+1, arr, k,dp); // har order ke partitoion ke ka suum saare check honge 
            maxians = max(sum, maxians);
        }
        return dp[ind] = maxians;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        // botto,down '
        for(int ind = n-1; ind>=0; ind--){
            int maxi = INT_MIN;
        int maxians = INT_MIN;
        int len = 0; // kitne tak gaye
             for(int j = ind; j< min(n, ind+ k); j++){
            len++; //har baar count hoiga uska 
            maxi = max(maxi, arr[j]); //maximum number ka count liya jayega , jo jitna maximum hai usse parition mai utni baar hi use multiply krwa denge 
            int sum = len*maxi + dp[j+1]; // har order ke partitoion ke ka suum saare check honge 
            maxians = max(sum, maxians);
        }
         dp[ind] = maxians;
        }
        return dp[0];
    }
};
