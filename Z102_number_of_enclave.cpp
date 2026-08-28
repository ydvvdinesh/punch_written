// same concept of surronded region only this time we are using bfs 
//approach - find 1 on the boundary then waah se traverse jo unke neghbour hai waah tak , jaha ruk mtlb 0 aa gaya or seaa hai toh ab jo beeche faise rh gye woh kabhi kinare pe nahi aayenge, aur hume woh btane answer jo land cell beech me faise rh gaye  (Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.) so jo visit bhi nahi huye hum se and 1 bhi hai unka count return karne kyuki usme hum bhi poch nahi payenge 
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        // queue is storing the coordinate jin boundary pe 1 hai staring phor toh traverse krenge toh cheze khud in ho jayengi 
        //traversing the boundary
        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++) {
                if((i == 0 || i == n-1 || // frist row , simple way to write
                    j == 0 || j == m-1) &&
                    grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        // now lets traverse to queue
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //trversing all side
            for(int i =0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow <n && ncol>=0 && ncol <m && vis[nrow][ncol] ==0 && grid[nrow][ncol] == 1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        int count = 0;
        for(int i =0; i<n;i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};
