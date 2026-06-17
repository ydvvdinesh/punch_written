//optimal approach - har row ko base manke use upper histogram bnayenge then , har array ka ka array nikalenge , jaise largest rectangle me nikla tha 
// so convert given matrix to our new matrix where every contain have from histogram 
//so we have to make histogram by adding upper one 
/* example -1 row1arr =[ 1 , 0 , 1 , 0 ,0]
   row2arr = [ 2,0,2,1,1]
   row3arr = [3,1,3,2,2]
   row4arr = [4,0,0,3,0] // yadi base hi zero toh histogram bnega hi nahi 
*/
//we are not going add again and again to convert the main matrix to histrogram 2 d matrix , we are using prefix sum
class Solution {
public:

    //function to find maximum area in histogram, deal in index
    int Largestone(vector<int> arr){
        int maxarea = 0;
        int n = arr.size();
        stack<int> st;
        for(int i =0; i<=n;i++){
            while(!st.empty() && (i==n || (arr[st.top()] >= arr[i]))){
                int height = st.top(); //height index , jisko leke nikal rahe hai
                st.pop(); // delete the larger one 
                int nse = i; // next smaller element index , jo abhi current ele hai uska
                //now after delting the top of stack we want to find the pse
                //but what if after deleting we get index we has higher value than current so then how it is previous smaler 
                /*
                The invariant The stack is maintained in strictly increasing heights.
Whenever a bar is popped, all bars taller than the current bar are removed first.
Therefore, after the while loop finishes:
int pse = st.empty() ? -1 : st.top();
the remaining top is guaranteed to be:
smaller than the current bar,
closest such bar on the left.
That's why it is the correct PSE.
                */
                int pse = (st.empty())?-1:st.top();
                maxarea = max(maxarea, arr[height]*(nse-pse-1));
            }
            if(i < n) st.push(i);
        }
        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size(); //columns
        int maxarea = 0;
        vector<vector<int>> prefixsum(n, vector<int>(m, 0));
        for(int j = 0; j<m; j++){//column  traversing primary
        int sum =0; // reset for every column 
            for(int i = 0;i<n;i++){//column traversing
            //adding from the upper one 
            sum += (matrix[i][j]-'0');
            if(matrix[i][j] == '0') sum =0 ;
            prefixsum[i][j] = sum;
            }
        }
        //now we are using the largest rectangle  for every row , in all row we have to find maximum
        for(int i = 0; i< n; i++){
            maxarea = max(maxarea, Largestone(prefixsum[i]));
        }
        return maxarea;
    }
};
