//maine galti se maximum sum waala likh diya , jaha maxiimumm waha minimum kardo

//yehi farak hai

//kisi bhi cell se start karna hai and kisi bhi cell pe khatam karna hai that`s means , ab har cell ke pas teen option hai , toh hum saare possible way try krenge hai last mai maximun return krenhe, isme hum 3 agah move kar skta hai 
class Solution {
public:
    //hum function multiple cell ke liye run kare ge , ye toh ek usable cheeze hai jo nbbaar baar use hoga 
    //row, column
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){ 
        int n = matrix.size(); //rows
        int m = matrix[0].size(); // columns
        //step -1 express  in the way and write base condition , ecxpress in the way means writing thei , j , matlab argument likhne hai 
        // hum niche se upper jayenge toh usse hisab se base case leekho , trabersal firection utli karke use krenge 
        if(j<0 || j >= m) return 1e9;
        if(i == 0){
            return matrix[0][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //step 2 do all stuffs so we are moving and do all traversal
        // current + next jo traverse karna hai i =0, tak jaise 0 aayega ek answer milege and woh milta aayega  har baar current ke saath add hokar and hun sun nik jayega
        int up = matrix[i][j] + func(i-1,j,matrix,dp); 
        int upleft = matrix[i][j] + func(i-1,j-1,matrix,dp); 
        int upright = matrix[i][j] + func(i-1,j+1,matrix,dp);
        return dp[i][j] = min(up,min(upleft,upright));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); //rows
        int m = matrix[0].size(); // columns
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int j = 0; j<m; j++){
            //every cell ke liye calll hogi 
            int ans = func(n-1,j, matrix, dp); 
            //phele iteration mestarting point hoga n-1 row ki 0 , woh khud i =0 tak jaate har cell hume 3 traversal se khu d ka maximum doond lenge and phir woh phir sabhi cell mai jo sabse jada maximum dega , woh choosse krnege 
            mini = min(mini, ans);
        }
        return mini;
    }
};
