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
    int funcdp(int ind, int K, vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(K + 1, 0));
        //base case
        //if index zero ka game and actually dono me hi zero hai dekho dhyan se  dp[0][0], for first index zero and for index sum is zero
        if(arr[0] == 0){ // first one
            dp[0][0] = 2; // yadi target bhi zero hai 
        }
        else{
            dp[0][0] =1;
        }
       // another base case, except ind 0 and ye dekh lena ye dp ,mai extra hai
        if (arr[0] != 0 && arr[0] <= K) {
            dp[0][arr[0]] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= K; target++) {
                int notpick = dp[ind - 1][target];
                int pick = 0;
                if (arr[ind] <= target) {
                    pick = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = (notpick + pick) % mod;
            }
        }
        return dp[n-1][K];
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += arr[i];
        }
        // negative or odd nahi hona chayiye
        if (totalsum < diff) return 0;
        if ((totalsum - diff) % 2 != 0) return 0;
        int s2 = (totalsum - diff) / 2;
        return funcdp(n - 1, s2, arr);
    }
};
