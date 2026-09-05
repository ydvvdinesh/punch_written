//pura same hai , dijisktra hi use ho raha hai bus hum of number of ways return karne hai shortest path ke 
// ways array will store woh index ya node kitne paths me aayi hai 
//raaaaaaaattttttttttttttt lo baad me samjah te hai
/*ways understanding - AAAAA
BETTER PATH MILA
        ↓
purane shortest paths hatao
        ↓
ways = parent ke ways

BBBBBBBB
SAME SHORTEST PATH MILA
        ↓
purane paths bhi valid
        ↓
naye paths bhi valid
        ↓
ways += parent ke ways
*/
//ye thoda kam samja aaya toh isko aache se dekhna 
class Solution{
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        int mod = 1e9 + 7; // Mod value
      vector<pair<int,int>> adj[n];
      for(auto it : roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
      }
 
     // Priority queue to store: {time or distance , node}
    priority_queue<
    pair<long long, int>,
    vector<pair<long long, int>>,
    greater<pair<long long, int>>
    > pq;
      pq.push({0,0});

     vector<long long> dist(n, LLONG_MAX);
      dist[0] = 0;
      //ways to store the number kitne path usse node se jayenge
      vector<int> ways(n,0);
      ways[0] = 1; //source se node i me jaane ke tarike 
      //we read it like from source zero to node 0 , jaane ka 1 hi tarika hai 
      
      while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            long long distance = it.first;

            // traverse the adjacent
            for(auto ti : adj[node]){
                int v = ti.first;
                int u = ti.second;
                //if we got a shortest distance , iska mtlb shortest path me bhi mila hi hai obvious hai 
                if(distance + u < dist[v]){
                    dist[v] = distance + u;
                    pq.push({dist[v],v});
                    //yadi samllest path mila , toh purane ways or raste htaoo , isko follows kro 
                    // Purane ways hatao // aur current node ke ways rakho
                    ways[v] = ways[node];
                }
                //yadi same distance mila toh , toh purane paath bhi valid hai and naye bhi toh dono ko consider kro 
                else if(distance + u == dist[v]){
                    ways[v] = (ways[v] + ways[node]) % mod;;
                }
            }
      }
      //last destination pe kitne paath aarahe hai total , peeche ke mila ke 
        return ways[n-1] % mod;
    }
};
