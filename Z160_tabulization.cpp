// fixture of 1 and 2 bus farak ye hai , jaise hum 2 me saare possible
// transction kar rahe the isme sirf 2 hi kar skate hai so un do transscation
// mai hi aapko sabse maximum profit find out karna hai
class Solution {
   public:
    // on which day , buy kiya ki nahi , cap maximum transctionkitni le skte hai
    // which is 2
    int func(int day, int buy, int cap, vector<int> arr,
             vector<vector<vector<int>>>& dp) {
        int n = arr.size();
        // base case
        if (cap == 0) {
            return 0;
        }
        if (day == n) {
            return 0;
        }
        if (dp[day][buy][cap] != -1) {
            return dp[day][buy][cap];
        }
        // ek din mai dono me se ek hi operation yaha hum uss din buy karenge
        // yaha sell krenge now yadi buy kiya toh , do hi cheeze hongi take that
        // day or don`t take that day
        int profit = 0;
        if (buy == 1) {
            // yadi phele buy kiya and why -ve aayega because it tell us ki
            // hmari traf se kitni value isme day , kyuki jab humne buy kiya toh
            // hmare paise toh khatam huwa na, yadi buy kar liya toh waah zero
            // hi aayega yadi buy ki toh capcity utni hi rhegi , kyuki capcity
            // kab ghetgi jab ek puri iteration hogi buy then sell
            int a1 = -arr[day] + func(day + 1, 0, cap, arr, dp);
            // ye manga hai dura lenge toh hmari traf se kuch negative huwa nahi
            // , hmare paass toh utne paise hi honge jitne phle the , buy waali
            // 1 rakhenge , becoz hum waah buy kar skte hai
            int a2 = 0 + func(day + 1, 1, cap, arr, dp);
            profit = max(a1, a2);
        }
        //
        else {
            // yadi woh din liya sell karne ko
            // jab sell krenge toh hmare pass toh paise badhenge
            // yadi sell hogaya toh matalb ek iteration ho gaya hai
            int b1 = arr[day] + func(day + 1, 1, cap - 1, arr, dp);
            // if we are not taking that day for selling, that means that can`t
            // add value or money to us
            int b2 = 0 + func(day + 1, 0, cap, arr, dp);
            profit = max(b1, b2);
        }
        return dp[day][buy][cap] = profit;
    }
    int stockBuySell(vector<int> arr, int n) {
        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        // base case ,a) yadi cap 0 hai toh baaki do kuch bhi ho woh return 0 hi
        // krega
        for (int day = 0; day < n; day++) {
            for (int buy = 0; buy <= 1; buy++) {
                dp[day][buy][0] = 0;
            }
        }
        // b) yadi last day(n), th return hoga zero
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 0; cap <= 2; cap++) {
                dp[n][buy][cap] = 0;
            }
        }    

            // till now base casee is completed
            //  we have to put the sum into dp array ,ye ulta move hoga , always
            //  opposite to recursion
            for (int day = n - 1; day >= 0; day--) {
                for (int buy = 0; buy <= 1; buy++) {
                    for (int cap = 1; cap <= 2; cap++) { // kyuki zero humne pehel hi fix kardi 
                        int profit = 0;
                        if (buy == 1) {
                            int a1 = -arr[day] + dp[day+1][0][cap];
                            int a2 = 0 + dp[day+1][1][cap];
                            profit = max(a1, a2);
                        }
                        //
                        else {
                            int b1 = arr[day] + dp[day+1][1][cap-1];
                            int b2 = 0 + dp[day+1][0][cap];
                            profit = max(b1, b2);
                        }
                        dp[day][buy][cap] = profit;
                    }
                }
            }
            return dp[0][1][2]; 
        }
};
