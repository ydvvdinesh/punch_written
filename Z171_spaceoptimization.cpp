class Solution {
public:
    int funcso(int n, int target, vector<int>& arr) {
        const int mod = 1e9 + 7;
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        // base case
        if(arr[0] == 0){ // first one
            prev[0] = 2; // yadi target bhi zero hai 
        }
        else{
           prev[0] =1;
        }
       // another base case, except ind 0 and ye dekh lena ye dp ,mai extra hai
        if (arr[0] != 0 && arr[0] <= target) {
            prev[arr[0]] = 1;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= target; tar++) {
                int notpick = prev[tar];
                int pick = 0;
                if (arr[ind] <= tar) {
                    pick = prev[tar - arr[ind]];
                }
                curr[tar] = (pick + notpick) % mod;
            }
            prev = curr;
        }
        return prev[target];
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
        return funcso(n , s2, arr);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};
