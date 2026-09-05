//most easy algoritham - copy hai dijisktra ki bus ye negative weight pe  bhi kaam karta hai , aapko shortest distance in negative weight ansd also it detected the negative cycle in graph - 
// negative cycle =  tottalpath of any cycle less negative 
//approach - relax the graph n-1 times distance array me khud shortest value store ho jayenge , intitutuin bahut easy ha
//and nth iteration pe distance array me koi value reduce ho rahi hai toh uska matlab hai , usme negative ccyle 
class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
	vector<int> dist(V,1e9);
    dist[S] = 0;
    // lets relax n-1 times or iterate n-1
    for(int i =0; i<V-1;i++){
        for(auto it : edges){
            // u is from 
            // v to
            int u = it[0]; // node 1
            int v = it[1]; // node 2
            int wt = it[2]; // edge weight
            //relaxing time 
            //dist[u] = distance to u from the source , or jo queue me cumulative distance hoti hai upper se judti hai 
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    //ab nth hi bachi hai kyuki hum upeer n-1 travel karke aa chuke hai 
    // this for detecting the negative cycle we are going to run the nth iteration
    for(auto it : edges){
        int u = it[0]; // node 1
        int v = it[1]; // node 2
        int wt = it[2]; // edge weigh
        if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;
	}
};
