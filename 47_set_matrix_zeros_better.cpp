//better approach , do array lo unko mark karo , 1 jab bhi koi zero mile and baad me jo bhi marked 1 one unko zero bnado
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(); // no of rows
    int m = matrix[0].size(); // no of column
    vector<int> column(m,0);
    vector <int> row(n,0);
    for (int i = 0; i<n; i++){
        for(int j=0; j<m;j++){
            if( matrix[i][j]==0){
                column[j]=1;
                row[i]=1;
            }
        }
    }
    for (int i = 0; i<n; i++ ){
        for(int j=0; j<m;j++){
            if (row[i] ==1 || column[j] ==1){
                matrix[i][j]=0;
            }
        }
    }
    
    }
};
