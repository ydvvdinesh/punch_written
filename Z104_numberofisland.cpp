//easy , hume total no of 1 ke groups btane hai, kyuki 1 hi land ko represent karta hai and that is woh milke island bnata hai
//approach - traverse complete array and jaise hi first 1 mile usse uske saare neighbours traverse krwayenge all 8 directions , and unko visted array me mark kr denege, in last jaha bhi one hai and wo visit nahi mtlb waah se start honge , aose total no of starting mil jayenge and note ek single node ya 1 bhi iskland ho skta hai , ye bilkul jarooori nahi ki saare 1 ho 
class Solution {
public:
    // ye function tabhi call hoga jab land hogi mtlb 1 , toh visted toh hoga hi isliye phele hi mark kar diya
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        // ye tabhi mark hai
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            //now we have to traverse to 8 direction in regular island but here we have to only 4 
            //our traditional method drow = {-1,0,1,0} for four 
            // for eight 3 row ke upper consider hogi 3 niche and 2 left right me 
            // drow [] = {-1,-1,-1,0,1,1,1,0}
            //is traditional way ko do looop me khatam kar denge
            /* 8 direction for(int drow = -1; drow <= 1; drow++){
    for(int dcol = -1; dcol <= 1; dcol++){*/

    
            //leetcode bol raha 4 direction only
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                    int nrow = r+ drow[i];
                    int ncol = c+ dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        // creation of the visted array , duplicate of the grid matrix
        vector<vector<int>> vis(n,vector(m,0));
        //traversing the visited array , because bfs maark kreega jaha 1 honge and jo visted bhi nahi and land bhi hai mtlb 1 bhi hai woh starting point hoga ya land hoga
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
