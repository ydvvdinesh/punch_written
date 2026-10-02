//same hai unique path 1 ki trayah, bus ek difference jaha 0 hai waha ja skte hi and jaha -1 hai waah nahi jaa skate , uske liye base case use karna pdega 
//memorization
class Solution {
public:
    // row , column 
        int func(int i, int j,vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }
        if(matrix[i][j] == 1){
            return 0;
        }
        if(i== 0 && j == 0){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = func(i-1,j,matrix,dp);
        int left = func(i,j-1,matrix,dp);
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> temp(m,0);
        for(int i = 0; i<n; i++){
                vector<int> curr(m,0);
            for(int j = 0; j<m; j++){
                int up = 0;
                int left = 0;
                if(matrix[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }
                if(i== 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }
                if(i>0){
                     up = temp[j];
                }
                if(j>0){
                     left = curr[j-1];
                }
                curr[j] = up + left;
            }
                temp = curr;
        }
        return temp[m-1];
    }
};
