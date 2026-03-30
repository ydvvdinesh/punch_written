//optimal
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        /*
        mat.size() 👉 number of rows
        mat[0].size() 👉 number of columns
        */
        int n = mat.size();
        int m = mat[0].size();
        int count_max = 0;
        int index = -1;
        if (mat.empty()) return {-1, 0};
        for (int i = 0; i<n;i++){ // this loop tranverse in the rows
         // find first occurrence of 1
            auto it = lower_bound(mat[i].begin(), mat[i].end(), 1);
            int count_ones = mat[i].end() - it; 
        if(count_ones>count_max || index == -1){
            count_max = count_ones;//maximum function hi hai
            index = i;
        }
    }
    return {index,count_max};
    }
};
