class Solution{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(m,1e9));
        dist[source.first][source.second] = 0; //source ki source se distance
        q.push({0,{source.first, source.second}});
        // imp edge case 
        if(grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)return -1;
        if(source.first == destination.first && source.second == destination.second) return 0;
        int drow[] = {-1, 0, 1 , 0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int distance = it.first; // ye culumulative distance hota hai source se juda aata hai shortest hota hai samje
            int row = it.second.first;
            int col = it.second.second;
            // now we have to traverse neighbour
            //for(auto ti :adj[node]), when adjacency list given
            //when we have to go then the direction
            for(int i =0; i<4;i++){
                int newrow = row + drow[i];
                int newcol = col + dcol[i];
                //newrow and newcol give the index of the next node 
                //check validity
                //waali jagah nahi jayenge
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1 &&
                distance + 1 < dist[newrow][newcol]){
                    dist[newrow][newcol] = distance +1;
                    // jaha mila waha rukenge and answer return kar denge 
                    if(newrow ==destination.first && destination.second == newcol) {
                        return distance + 1;
                    }  
                    q.push({dist[newrow][newcol], {newrow, newcol}});
                }
            }
        }
        return -1;
    }
};
