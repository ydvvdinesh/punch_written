//most easiest of dp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // simple formula to solve this 
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        //replicate the first row and col in teh matrix
        //column fillinf
        for(int i = 0;i<m;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int j = 0;j<n;j++){
            dp[j][0] = matrix[j][0];
        }
        //after filling we have to traverse in the matrix and put the number in the arry ki kiss cell se hum kitne square bna skte hai, main cell ke number kki counting kre toh dp ke upper ke 3 diagonal use honge 
        for(int i = 1; i<n; i++){
            for(int j =1; j<m; j++){
                if(matrix[i][j] == 0){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min({
                    dp[i-1][j],      // top
                    dp[i][j-1],      // left
                    dp[i-1][j-1]     // top-left
                    }) + 1;
                }
            }
        }
        //now dp is storing konsi cell kitne bna skti hai woh number range and unko sab ko ghin lenge then we will the guy who is giving us the main thing 
        int sum = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ; j++){
                sum += dp[i][j];
            }
        }
        return sum;
    }
};
