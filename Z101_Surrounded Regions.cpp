//traerse the boundary , yadi boundary pe O mila toh usko note krlo and waase dfs start kardo , dfs will infrom ki uss boundary set me aur kitne hai then after completeing the dfs , we got a set jo replace nahi hoga , becuase jp boundary pe hai uski ek side toh pkka X se surrond nahi hoga , bas simple idea hai 
class Solution {
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int drow[], int dcol[]){
         int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        // check for the 4 posotionn
        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, vis, board, drow, dcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        //no of rows and columns
        // lets create visited array that tellus in which konsa visit hoga and konsa rh gaya
        vector<vector<int>> vis(n, vector<int>(m,0));
        //for neighbour
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        // lets traverse the all 4 boundary
        // first row and last row, row same and column difeerent
        for(int j = 0; j<m; j++){
            if(vis[0][j] == 0 && board[0][j] == 'O'){
                dfs(0,j,vis,board,drow, dcol);
            }
        }
        
        for(int j = 0; j<m; j++){
            if(vis[n-1][j] == 0 && board[n-1][j] == 'O'){
                dfs(n-1,j,vis,board,drow, dcol);
            }
        }
        // now for the first and last column
        for(int i = 0; i<n; i++){
            if(vis[i][0] == 0 && board[i][0] == 'O'){
                dfs(i,0,vis,board,drow, dcol);
            }
        }
         for(int i = 0; i<n; i++){
            if(vis[i][m-1] == 0 && board[i][m-1] == 'O'){
                dfs(i,m-1,vis,board,drow, dcol);
            }
        }
        //after traversing the all boundary , dfs marked that which boundary o so they caanot caanot , everything will be store in vissted array now we traverse the visited array
        // yadi jo visited nahi huwa and O bhi hai that means suroronded by the x, unko sirf O se replace krenge becuase waah tak dfs nahi pauch paaya that means woh boundary se start hoke beech me hi aatak gaya, mtlb jarror usko aage koi 0 nahi mila 
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
