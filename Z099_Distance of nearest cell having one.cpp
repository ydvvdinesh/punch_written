class Solution{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid){
   int n = grid.size();
        int m = grid[0].size();
        //no of rows
        // no of columns
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dis(n, vector<int>(m,0));
        //declaration of two vectors
        //declaration of visted array which tells us that till now we reached how many and which one and hum aage proceed karna hai ki nahi
        //declaration of dist which store the answer
        //for bfs , we have to decalre queue
        queue<pair<pair<int,int>, int>> q;
        // queue is going to store the three things , first two is coordinates and third one is the distance or steps from 1 to reach out to zero , nearest 0 from 1 , steps taken by 1 to reach out to o both things is same
        //first step to find out the which elements have, then push them to queue with visted array me mark karke
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0; // yadi nahi hai toh zero mark kardo
                }
            }
        }
        // till now we putted all one in the queue and get it coordinate , through every front we reach out to neighbour of one and , saath saath step calculate kar lenge , jab tak queue khatam hogi them hamara dist girid correct value se bhara hoga

        //for travesring to neighbour 
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            // storng the steps becuase woh hio toh return karna hai
            dis[row][col] =steps;

            //now traverse to every direction
            for(int i= 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                //main condition jo viste nahi hue hai woh visit ho jaye
                if(nrow>=0 && nrow<n && ncol >=0 && ncol <m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dis;
    }
};
