// optimal approach -  observation -right to bottom to left to top traversal karna hai
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();// no of rows
        int m = matrix[0].size();//no of columns
        //ye dono column ke part me include hote hai
        int left = 0; // first waala column
        int right = m-1;//lastwaala column
        //ye rows ke part hai
        int top = 0; // first waali row
        int bottom = n-1; // last waali row
        while(left<=right && top<=bottom){
            //moving to right
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);//top wali ro toh constant rhegi na and column waali me move krnege 
            }
            top++; // now we have to move to bottom and we have tp start from next element
            //moving to bottom
            for (int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);//ab right waala constant how and row me iterate kregi one by one
            }
            right--; // kyuki left i trf move karna hai
            if(top<=bottom){ // kyuki top increase and what if one hi row ho toh
            for (int i = right;i>=left;i--){
                ans.push_back(matrix[bottom][i]); //jisme iterate karna hai usme i ko daalo
            }
            bottom--;
            }
            if(left<=right){ //right decrease isliye
            for (int i = bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++; // kyuki jab poora traversal khatm hoga toh hume aandr waale se start karna hoga
        }
        }
        return ans;
    }
};
