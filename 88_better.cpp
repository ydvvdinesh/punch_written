// better approach 
//sorted ka fyado lo first and last dekho , har row me starting from 0th and jaha mile toh har column check mat kro direct bs lga dekho
//kyuki jis line me target hoga wo definately single array ki trah hi treat hogi
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

class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size();
        int m = mat[0].size();
        for (int i =0; i<n;i++){
            if (mat[i][0] <= target && target <= mat[i][m-1]){
                return bs(mat[i],target);
            }
        }
        return false;
    }
};
