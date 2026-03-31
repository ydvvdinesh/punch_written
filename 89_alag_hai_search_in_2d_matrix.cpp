//bruteforce
//isme bas index dena, same hi 1 ke , bas optimal mast hai
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i<n;i++){
            for (int j =0;j<m;j++){ // yaha column ka m aayega naki n dhyan rakho
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
};

/*Feature	Problem 74	Problem 240
Row sorted?	Yes	Yes
Column sorted?	No (only implicit via first>last)	Yes
Flatten into 1D sorted array?	✅ Yes	❌ No
Solution type	Binary search on 1D	Staircase search (top-right or bottom-left)
Time Complexity	O(log(m*n))	O(n + m)*/
