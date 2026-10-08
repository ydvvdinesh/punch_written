// recursion - bahut easy hai , n-1 to 0 jayega , isme hum target jod jode ke
// nahi bna raahe rahe , hum isme ghta .subtract kar rahe hai jaise hi target
// zero hoga kiski subsequence that means unke element ko jode go toh target
// mile ga bahut purani technique , we solve negative one phir jo bcha woh toh
// positive ho hi jayega memoziation main int dp store kyuki isme sirf check kar
// rage hai dp mai bool karni hogi
class Solution {
   public:
    // the function tells that till ind index of that array which get our taregt
    // or not
    bool check(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        int n = arr.size();
        // base case for target
        // hum ulta chle rhe , mtlb subtract karke -ve mai pauch rahe hai
        if (target == 0) {
            return true;  // thta means woh subaarray sahi answer de raha hai
        }
        // base case for index , yadi hum index 0 me hai toh yadi hume target
        // match karwana or condition satisifes krwani hai toh hum woh zero
        // index ke element jitna element chayiye jisse tareget zero ho jaye aur
        // we can say jitna target ka bacha hai utni value zero index pe honi
        // chayiye jabhi zero return krega
        if (ind == 0) {
            return (arr[0] == target);
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        // now explore all paths
        // yadi nahi ke rahe toh ek ind piche chle jayenge and target mai se
        // kuch nahi dsubtract kre nge its commonsense , jab woh uska part hai
        // hi nahi toh kasie help krega target tak pauchne mai
        bool nottake = check(ind - 1, target, arr, dp);
        bool take = false;
        if (target >= arr[ind]) {
            take = check(ind - 1, target - arr[ind], arr, dp);
        }
        // kyuki yadi jisko le rahe haui woh target ko cross kar gay toh woh
        // tareegt toh nahi mila na issliye chota hona chayiye question is
        // asking yadi ek bhi subsequence exist krta hai toh return yadi ek mil
        // gaya toh dusra kyu check karna
        return dp[ind][target] = (take || nottake);
    }

    // sab kuch opposite
    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();
         vector<bool> prev(target + 1, false);
          vector<bool> curr(target + 1, false);
        // n-1 to zero ki trf jayenge
        // base case
        // yadi target zero hai toh
        for (int ind = 0; ind < n; ind++) {
            prev[0] = true;
        }
        if (arr[0] <= target) {
            prev[arr[0]] = true;
        }

        // jitne varible utne loop
        for (int ind = 1; ind < n; ind++){
            for (int i = 1; i <= target; i++) {  // opposite to last one
                bool nottake = prev[i];
                bool take = false;
                if (i >= arr[ind]) {
                    take = prev[i - arr[ind]];
                }
            curr[i] = (take || nottake);
            }
            prev = curr;
        }
        return prev[target];
    }
};
