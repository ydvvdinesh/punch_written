// question - cheapest cost/distance btaoo with k stops
//approach - complete dijsktra hai , but reemeber one thing ditance ko supremee nahi stops ko supreme bna ke karna hai kyuki yadi distance ko supremee bnaya toh k se jaada stop bhi ja skate hai 
// distance array = ka kaam hota hai minimum value rakhna apne index pe and yadi jo si destination boli hai uss index ki value dedo wohi answer hoga , kyuki distance array toh shortest / cheapest cheeze hi rakhta hai apne index pe
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // converts edges to directed graph 
    vector<pair<int,int>> adj[n];
    for(auto it : flights){
        adj[it[0]].push_back({it[1], it[2]});
    }

    //we get a adjancy list
    vector<int> dis(n,1e9);
    dis[src] = 0;
    //queue {stops,{node, distance or cost}}
    //stops is leading here, queue over priority queue because stops toh 1 step se badhenge and minimum yadi pehele layenge toh bhi toh bhi wohi aayega 
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int distance = it.second.second;
        if(stops > k) continue;

        // now traverse to adjcent node 
        for(auto ti : adj[node]){
            int v = ti.first; //adjacent node
            int u = ti.second; //weight of that respective node 
            if(distance + u < dis[v] && stops <= k){
                dis[v] = distance + u;
                q.push({stops+1,{v,dis[v]}});
            }
        }
    }
    if (dis[dst] == 1e9) return -1;
    
    return dis[dst];
   }    
};
