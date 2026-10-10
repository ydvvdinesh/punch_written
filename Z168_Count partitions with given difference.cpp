// same like upper count the subsets with sum k
// isme hum kuch change karege and exact sum , ham isme target ka formula denge
// woh use karna hai problem - ek subset diy hoga uske do partioin karne karne
// hai jisme s1 is greater than s2 and jin do subsets ka dufference aayega unn
// dono subset ko counts krega
//  s1 -s2 = d -> given
// s1+s2 = totalsum ->our finding
/*
modifications
s1 = d + s2, put into equation 2
d + s2 + s2 = totalsum so d + 2s2 = totalsum, s2 = (totalsum - d)/2
s2 is the sum od subset , isko hum target ki jagah use krenge ab jo subset s2 ke
sum mai aayega , obssivble saari condition mai fit hoga , so ghooma ke kaan pkda
hai
*/

class Solution {
   public:
    // function for counting subsets of sum k
    int func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        // base case
        // har baar last index me jaana hai yadi waha sum zero hai toh 1 return
        // krenge , and sum ke saath uss array ka index bhi zero hai toh return
        // 2 , naye base case speciallu iss arr = {0,0,1} array ko soch ke bnaye
        // hai
        if (ind == 0) {
            if (target == 0 && arr[0] == 0) return 2;
            if (target == 0 || target == arr[0]) return 1;
            return 0;
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        int notpick = func(ind - 1, target, arr, dp);
        int pick = 0;
        if (arr[ind] <= target) {
            pick = func(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = (notpick + pick) % mod;
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += arr[i];
        }
        //negative or odd nahi hona chayiye
        if (totalsum < diff) return 0;
        if ((totalsum - diff) % 2 != 0) return 0;
        int s2 = (totalsum - diff) / 2;
        vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
        return func(n - 1, s2, arr, dp);
    }
};
