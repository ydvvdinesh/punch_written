// question - shortest path from the source 
//approach - using a minimum heap(priority queue), jiski distance choti top me woh rhega , phela operations uspe hoga , 
// aur toh wohi hai distance me sab daalte jaoo , jab chota trigger ho toh usko daal do 
class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {
        // create a adjancy list 
        vector<pair<int,int>> adj[V];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]}); // both directional graph4
            adj[it[1]].push_back({it[0],it[2]});
        }
        //declare the priority queue
         priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
          vector<int> dist(V,1e9);
          // distance from the source is zero, and push to priority queue
          dist[S] = 0;
          pq.push({0,S}); //distance and source phele distance aayega
          
          // now start the loop
          while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            // now traverse to adjancy list, toh adjacy list me phele node hoti hai then uska weight hota hai toh confuse mat hona upper and neeche me 
            for(auto it : adj[node]){ //ye loop me node apna aashtitav it me baat chuki hai
                int v = it.first; //node
                int u = it.second; //weight of that respective node 
                //yadi jo distance phele se maintain hai distance array me yadi usse choti hai toh hi replace karna
                if(distance + u < dist[v]){
                    dist[v] = distance + u;
                    pq.push({dist[v], v});
                }
            }
          }
        return dist;
    }
};
