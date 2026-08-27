//jab do baar array ka index visted ho jaye
//bfs se jayenge and vector me jo visit kar liya usko mark kar denge and then jab dusri baar hum concide /conflict ho jaye mtlb cycle hai 
class Solution{
public:
//function to traverse through the graph 
    bool detect(int src, vector<int> vis, vector<int> adj[]){
        vis[src] = 1;
        // we are storing node and its parent , last me kaam aayega parent waali cheeze me
        queue<pair<int,int>> q;
        q.push({src,-1}); //-1 is imaginary thing
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){ // it, representing the adhjacent node , it`s a variable
                if(vis[it] == 0){
                    vis[it] = 1;
                    q.push({it, node});
                }
                //jo parent ho woh 2 baar vist kar skata hai isliye usko include mat karna 
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]){
        vector<int> vis(V,0); 
        // for the connected component also , 
        for(int i = 0; i<V; i++){
            if(vis[i] == 0){
                if(detect(i,vis,adj)) return true;
            }
        }
        return false;
    }
};
