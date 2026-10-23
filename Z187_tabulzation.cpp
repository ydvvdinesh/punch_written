// we have to convert the string 1 into string 2 using three operations insert ,
// delete and replace , insert and selte waala toh hum just karke hi aaye hai

class Solution {
   public:
    // i is the index of start string and j is the index of target string
    // this function gives us a answer that tells us the minimum no of the
    // operations used to convert s1(0.....i) to s2(0............j)
    int func(int i, int j, string start, string target,
             vector<vector<int>>& dp) {
        int n = start.size();
        int m = target.size();
        // base case
        if (i < 0) {
            return j + 1;  // j+1 operation lgegnge target bnana mai yadi start
                           // puri traverse kardi toh
        }
        if (j < 0) {
            return i + 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // exxplore all possiblites
        // if the two index matched, toh operation karke ki koi jaroort nahi hai
        // agle pe badho , isliye value 0 aayegi
        if (start[i] == target[j]) {
            return dp[i][j] = 0 + func(i - 1, j - 1, start, target, dp);
        }
        // yadi matched nai hai toh , alag hai matlab toh humne pass teen tarike
        // hai
        else {
            // 1, isliye kyuki ek inseration huwa nah
            // inseration mtlb woh index pe cheez add ho gayi toh toh phele
            // index toh wahi rheg and dusra piche aayega kyuki jo humne insert
            // koya usse merged ho jayega
            int insertion = 1 + func(i, j - 1, start, target, dp);
            // deletion kiya toh start waale pe move krenge , ek piche jayegnge
            // and target waala wahi rhega common sense
            int deleteion = 1 + func(i - 1, j, start, target, dp);
            // replace mai dono hi piche jayegnge kyuki phele waala matched kar
            // hi hayega
            int replacegame = 1 + func(i - 1, j - 1, start, target, dp);
            return dp[i][j] = min(insertion, min(deleteion, replacegame));
        }
    }
    int editDistance(string start, string target) {
        int n = start.size();
        int m = target.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n - 1, m - 1, start, target, dp);
    }
};
