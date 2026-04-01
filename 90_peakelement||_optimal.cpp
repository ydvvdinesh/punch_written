//optimal - ek elemnt apne adjacent uper neeche left and right sabse bda hoga 
//ek dum esay find a maximum element in the column and , upper down se toh automaticaally and left right ka hum check krenge lenge 
//this function gives us the index of row in which maximum elemnt of column lie
int func(vector<vector<int>>& mat,int n, int m, int col){
     n = mat.size();
     m = mat[0].size();
    int maxi_value = -1;// ye variaable peeche value store krta jayega , ye maximum function hi hai
    int index = -1;
    for (int i = 0;i<n;i++){
        if(mat[i][col] > maxi_value){
            maxi_value = mat[i][col];
            index = i;
        }
    }
    return index;
}
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low =0;
        int high = m-1; // m column se kr rha hu aap row se bhi kr skte hai
        //we go with function
        while (low<=high){
            int mid = (low +high)/2; // mid columns se khelega
        //count the maximum element of the row 
        int row_max_index = func(mat,n,m,mid); // woh row jaha usse column ka maximum element mila hai 
            int left;
            int right;
            //left value nikal rhe hai
            if (mid -1 >=0){
                left = mat[row_max_index][mid -1];
            }
            else{
                left = -1;
            }
            //right value nikal rhe hai
            if (m > mid +1){
                right = mat[row_max_index][mid+1]; // mid +1 kyuki next hai na
            }
            else{
                right = -1; //You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
            }
            // main condition
            if(mat[row_max_index][mid]> left && mat[row_max_index][mid]> right){
                return {row_max_index,mid};
            }
            else if(mat[row_max_index][mid]> left){
                low = mid + 1; // yadi left se bda that means right men hoga so eliminate row
            }
            else{
                high = mid -1;
            }
        }
    return {-1,-1};    
    }
};
