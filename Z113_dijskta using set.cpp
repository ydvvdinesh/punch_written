// using set 
//priority queue over queue , because in queue you have to go with a manner first infirst out but in priority queue jiski value kaam hogi woh jaldi top bnega , kahi baar multiple node aati repeat ho jaati hai isme 
//set over pq , sab same hai bus unique aayga
class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> edges, int S) {
        // convert edges into graph 
        vector<pair<int,int>> adj[V];
        for(auto it : edges){
            int a = it[0];
            int b = it[1];
            int c = it[2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        // graph is created
        set<pair<int,int>> st; //distance, node
        vector<int>dist(V,1e9);
        st.insert({0,S});
        dist[S] = 0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int distance = it.first;

            // Remove current pair
            st.erase(st.begin());

            for(auto ti : adj[node]){
                int v = ti.first; // node 
                int u = ti.second; // weight

                    if(distance + u < dist[v]){
                        // Remove old pair if it exists
                    if(dist[v] != 1e9) {
                        st.erase({dist[v], v});
                    }
                        dist[v] = distance + u;
                        st.insert({dist[v], v});
                    }
            }
        }
        return dist;
    }
};
