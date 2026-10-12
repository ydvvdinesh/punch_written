int funcdp(int n, int target, vector<int>& arr) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // base case
        if(arr[0] == 0){ // first one
            dp[0][0] = 2; // yadi target bhi zero hai 
        }
        else{
           dp[0][0] =1;
        }
       // another base case, except ind 0 and ye dekh lena ye dp ,mai extra hai
        if (arr[0] != 0 && arr[0] <= target) {
            dp[0][arr[0]] = 1;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= target; tar++) {
                int notpick = dp[ind - 1][tar];
                int pick = 0;
                if (arr[ind] <= tar) {
                    pick = dp[ind - 1][tar - arr[ind]];
                }
                dp[ind][tar] = (pick + notpick) % mod;
            }
        }
        return dp[n-1][target];
    }

    int countPartitions(int n, int diff, vector<int>& arr) {
        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += arr[i];
        }
        // total sum of the array
        if (totalsum < diff) return 0;
        if ((totalsum - diff) % 2 != 0) return 0;
        int s2 = (totalsum - diff) / 2;
        return funcdp(n , s2, arr);
    }
