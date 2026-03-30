//brute force but better than optimal approach 
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();//no of rows
        int m = mat[0].size(); // no of columns
        int count_max = -1;
        int row_index = -1;
        for(int i = 0; i<n;i++){
        int count_sum = 0;// count sum of everyrows , becoz jitna sum utne one , har baar reset krna pdta new pe jaane ke baad
        for (int j = 0; j<m; j++){
            count_sum += mat[i][j]; 
        }
        if(count_sum>count_max){
            count_max = count_sum;
            row_index = i;
        }
        }
    return {row_index , count_max}; //yaha count max aayega , naki count sum ,  we are storing count sum data in count max
    }
};
