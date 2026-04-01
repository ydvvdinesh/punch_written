//optimal - hum stair ki trayh kaam krenge 
//har row and colum sorted hai
//ek corner pe khadehonge jaha se ek increasing rasta hog and a decreasing rasta and eliminate krte chlenge simple hai
//let example - ek element pe khde huye , usko dekhenge ki wo target hai , if hai toh answer mil gaya 
//if nahi h toh uss element ko target se compare krwayege , yadi chota hai toh pkka uski left side of row puri choti hogi toh wah target nhi mil rha eliminate that and move to next row in same columns, column tab hi change hoga jab elemnet h target se bda hai toh
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row =0;
        int col = m-1;
        while(row<n & col>=0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col]<target){
                row = row + 1;
            }
            else{
                col = col - 1;
            }
        } 
        return false;
    }
};
