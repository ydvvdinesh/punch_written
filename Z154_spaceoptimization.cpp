// do vector mai sab store kare rahe , prev m sab store ho raha and curr usko usko use kar raha ha , we are converting from tabluzation to space optimisation//simple way change karne ka -1 ko preb likh do and simple ko current 
//it not facts but a trick dp[i-1] - prev and dp[i] - curr
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0);// kyuki row mai traversekar rahe hai 
        vector<int> curr(m,0);
        // base case 
        for(int j =0; j<m; j++){
            prev[j] = matrix[0][j];
        }
        //now use the traversal thing and woh j waala base case dhyan rakhna
        //already base case fill ho chuka hai 
        for(int i = 1; i<n; i++){
            for(int j =0; j<m; j++){
                int up =0;
                int upleft = 1e9; 
                int upright = 1e9;
                up = matrix[i][j] + prev[j];
                if(j>0){
                 upleft = matrix[i][j] + prev[j-1];
                }
                if(j+1<m){
                 upright = matrix[i][j] + prev[j+1];
                }
                curr[j] = min(up, min(upleft, upright));
            }
            prev = curr;
        }
        
        // har cell ki call karna uss row toh ab saabka minimum doondennge
        int mini = INT_MAX;
        for(int j =0;j<m;j++){
             mini = min(mini, prev[j]);
        }
        return mini;
    }
};
