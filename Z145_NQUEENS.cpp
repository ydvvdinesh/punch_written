class Solution {
public:
    bool canweplaceit(vector<string>& board, int roww, int coll){
        int n = board.size();
        int row = roww;
        int col = coll;
        //top
        while(row >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
        }

        row = roww;
         col = coll;
        //+45
        while(row >= 0 && col <n){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }

        row = roww;
        col = coll;

        //left one 
        while(row >= 0 && col >=0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        return true;
    }

    void func(int row, vector<vector<string>>& ans,vector<string>& board){
        int n = board.size();
        if(row == n){
            ans.push_back(board);
            return;
        }
        //har column 
        for(int col = 0; col<n; col++){
            if(canweplaceit(board, row, col) == true){
                board[row][col] = 'Q';
                func(row+1, ans, board);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        func(0,ans, board);
        return ans;
    }
};
