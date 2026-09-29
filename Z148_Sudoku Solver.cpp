//question ek dum easy hai
//step -1 go to empty cells and 1 se leke 9 tak saare numbers bharne ka try karo , and jo numer teeno rule ko satisfy kar de sirf usko rakhna 
//rule -1 kisi bhi row me same element nahi honge
//rule -2 kisi bhi column me same element nahi honge 
//rule -3 3x3 ke har grid me alag number honga 
class Solution {
public:

    //rule mapped 
    bool isrulemapped(vector<vector<char>>& board, int row, int col, char digits){
        int n = board.size();
        //variable for grid, by observation striver ne ek dum perfect smjaye hai 
        int startrow = (row/3)*3;
        int startcol = (col/3)*3; 
        for(int i = 0; i<n;i++){
        //checking in row, row same rhegi and column change hote rhenge 
            if(board[row][i] == digits){
                return false;
            }
        //checking in col
            if(board[i][col] == digits){
                return false;
            }
        //chcking into grid, ye bhi observation se explain kiye hai 
            if(board[startrow + i/3][startcol + i%3] == digits){
                return false;
            }
        }
        return true;
    }

    //recursive function
    bool func(vector<vector<char>>& board){
        int n = board.size();
        //find empty cells fist
        for(int i =0; i<n;i++){
            for(int j =0; j<n; j++){
                if(board[i][j] == '.'){
                    //once we find, first we think about rukes woh lag rahe hai ki nahi
                    for(int digit = '1'; digit<='9'; digit++){
                        if(isrulemapped(board,i,j,digit) == true){
                            board[i][j] = digit;
                            bool val = func(board);
                            if(val == true){
                                return true;
                            }
                            //else
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        func(board);
    }
};
