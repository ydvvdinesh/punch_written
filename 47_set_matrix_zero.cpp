class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        /* iss baar array declare mat kro bas understanding ke liye comment me rakho wo jyada important hai
           column = matrix[0][j], vector<int> column(m,0)
           row    = matrix[i][0], vector<int> row(n,0)
        */

        int n = matrix.size();      // size of rows
        int m = matrix[0].size();   // size of column

        int col0 = 1; // column ka part ko upper kiside hum bhejte hai, ki row waala array disturb na ho

        /// marking hogi
        for (int i = 0; i < n; i++) {

            // agar first column me hi zero mila toh col0 ko 0 kar do
            if (matrix[i][0] == 0) col0 = 0;

            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) { // marking chal rahi hai
                    matrix[i][0] = 0;   // row will be zero
                    matrix[0][j] = 0;   // column will be zero
                }
            }
        }

        // reassignment, jaha jaha mark hai waha hum ab value ko zero karenge
        for (int i = 1; i < n; i++) { // kyuki beech se reiterating karni hai
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // last: agar matrix[0][0] zero hai toh poori first row zero karo , mtlb column aaray ko
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // last: agar col0 zero hai toh poori first column zero karo , mtlb aaray ko
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
