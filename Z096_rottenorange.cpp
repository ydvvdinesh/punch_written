//simple hai bus thode code bada hai 
//kuch rotten orange di hongi jo 2 se represnt hongi in matrix , so we have to find the minimum time jisme saari oranges rotten ho jaye , jitne rotten hai woh apne negihbour jko rotten krengi , upper niche left and right , digonally nahi krenge , one more thing t iteration ke hisab se chlega , har rooten dusri ko rotten karne me unit second lgeyangi jo one hogi , and usse 1 sec me jitni bhi rotten hai woh neigh bour ko rotten krengi then hum next second pe pauchenge 
//ek cheeze notice karna hum level wise dusre ko rooten kar rahe hai so isliye bfs use krenge because hum neighbour ko rotten kar rahe hai 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //grid is the given array which consist of rotten orange, fresh orange, no orange
        int n = grid.size();
        //no of rows of the grid
        int m = grid[0].size();
        //no of columns of the grrid
        int countfresh = 0; // count fresh oranges
        queue<pair<pair<int,int>, int>> q;
        //we created a queue , because we use it in bfs , we are storing row , column, time is used/ put to rotten the neighbour
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //declaration of visited array jo hume btayega hum kon si fresh organes ko rotten kar chuke that gave us idea ki ab konsi karni hai 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){ //yadi jispe gaye woh rotten hai toh daalo queue me 
                    q.push({{i,j},0}); //0 because we are pushing the first one in one level iteration thats why time is zero
                    vis[i][j] = 2; //mark to visited array 
                }
                else if(grid[i][j] == 1){
                    countfresh++;
                }
                else{
                    vis[i][j] = 0; // toh mtlb phir waha orange nahi hai 
                }
            }
        }
        //this loop will helps us to find the rooten oranges, start to put them into queue then jisko q se htayenge , uske neighbour ko daalenge and aise karte karte jab sab traversal ho jayege jo maximum answer aayega wohi answer hoga 
        
        int tm =0;
        // it use to store the minimum time to rotten all the eggs 
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        //theese are the way through them we traverse the number , row se downward jaate hai toh +1 hote hai upper jaate hai toh -1 , same vaise hi cheeze run hoti hai 
        //kyuki inko bhi rotten karke queue me daalna hai 
        //ye hi main step hai yaha hum har not rotten ko rotten karke queue me daal rahe hai
            int cnt = 0; // ye woh count kar rahe kitne hum fresh se rooten kiye
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            // we have to rott the neighbour , every rotten organge have three neighbour
            for(int i =0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                //its neighbour row and col
                //once we rotted the orange now push it to queue
                //here we are setting the limits, jo rooten nahi hai unhe hi karna hai, jo fresh 
                if(nrow >=0 && nrow <n && ncol >= 0 && ncol <n && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol}, t +1});
                    vis[nrow][ncol] =2;
                    cnt++;
                }
            }
        }
        //yadi jitne humne fresh se rotten kiye , yadi woh starting ke fresh ke equal nahi hai matlab dikkat hai , kyuki dono same ghome chayiye , kyuki hum fresh ko hi toh rotten kar rahe hai
        if(cnt != countfresh) return -1;
        return tm;
    }
};
