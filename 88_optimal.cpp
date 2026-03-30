//optimal - using bineary search , mid hoga woh 1d array ka maan lenge (suppose)
//frontend me 2d matrix pe kaam krenge but backend pe 1d soch ke krenge
class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size();//no of rows 
        int m = mat[0].size(); // no of column
    //techincally we don`t flatten the 2d matrix into one d but here we are thiniking in that way per code m, n ki form hi likhenge
    // hypothecially we convert 2d into 1 d 
    //suppose we have a matrix we write every one in 1d array in sorted format and then using bs we find easily , it is very easy for us 
    //convert index (index of 1d array) from one d to 2d , 
    /*
    row = (1d array)index/m(no of column)
    column = index % m 
    */
    int low = 0;
    int high = n*m -1; // last element 
    while (low<= high){
        int mid =  (low + high)/2;
        int row = mid/m;
        int col = mid %m;
        if(mat[row][col]==target){
            return true;
        }
        else if(mat[row][col] < target){
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    return false;
    }
};
