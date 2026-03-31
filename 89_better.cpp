//better approach - same like 74 search a 2d matrix only ek condition ka difference h
bool bs(vector<int> arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if (arr[mid] == target){
            return true;
        }
        else if(target >arr[mid]){
            low = mid + 1; 
        }
        else{
            high = mid -1;
        }
    }
        return false;
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i =0; i<n;i++){
         if (bs(matrix[i], target)) { // ye condition alag hai 
                return true; // kya pta target khh ho kyuki independent h row and column
            }
        }
        return false;
    }
};
