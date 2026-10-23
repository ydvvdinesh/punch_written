// we have to convert the string 1 into string 2 using three operations insert ,
// delete and replace , insert and selte waala toh hum just karke hi aaye hai

class Solution {
   public:
    int editDistance(string start, string target) {
        int n = start.size();
        int m = target.size();
        // same hai bus string me zero based indexing and , in comparing one
        // based ,
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        // base case
        // indexing ki wajah se ab j hi aayega and usme i hi aayega , kyuki ab
        // last 0hi hoga phele -1 that ab 1 based indexing ka game chlega
        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }
        for (int i = 1; i <= n; i++) {
                curr[0] = i;
            for (int j = 1; j <= m; j++) {
                //-1 isliye ab zero hi aayega bounde se bahar nahi jayega
                if (start[i - 1] == target[j - 1]) {
                    curr[j] = 0 + prev[j - 1];
                } else {
                    int insertion = 1 + curr[j - 1];
                    int deleteion = 1 + prev[j];
                    int replacegame = 1 + prev[j - 1];
                    curr[j] = min(insertion, min(deleteion, replacegame));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
