//kya karna hai- ek color give milege with sc and sr(starting row), ab jaise kar usse inital waale ka aise jitno ka bhi colour hai sabko new color se replace kardo 
class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int newcolor, int drow[], int dcol[], int inicolor){
        // function is use to traverse from given row and col and ye deptth search krega and sab connected and adjacent hai toh dheere dheere saara complete ho jayega
        int n = image.size();
        int m = image[0].size();
        // this give size of row and column 
        // Current cell ko new color de do
        ans[row][col] = newcolor;
        // now we have to move 4 side 
        for(int i =0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            // till now we find a way to went on adjacent , now we puuting the condition through we get to know ki , usse same color ke kitne then uspe hum naya rang daalega 
            //image[nrow][ncol] == inicolor most image , tabhi usko traverse krenge
            if(nrow>=0 && nrow<n && ncol >= 0 && ncol <m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor){
                dfs(nrow, ncol, image, ans, newcolor, drow, dcol, inicolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int intial_image = image[sr][sc];
        // till now we get our intial image, ab ye color jiske un sabo new color se rang do 
        vector<vector<int>> ans = image;
        // used to store the final return ye he return krenge
        //now just call dfs , woh khud traverse kr dega , but before hume upper niche left right me move karna hai uska step karna 
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        //calling dfs, from the starting uske baad toh upper function leekha woh kaam kard dega
        dfs(sr,sc,image, ans, color, drow, dcol, intial_image);
        return ans;
    }
};
