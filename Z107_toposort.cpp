//topo sort only works in DAG DIRECTED ACYCLIC GRAPH , this algo gives you a order if the graph in in u is appears first thanin v in order , u->v
//ek dum easy hai , traverse krte raho , list dekh ke and dfs call karlo wo direct traverse kar lega 
class Solution{
public:

    void dfs(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] == 0){
                dfs(it,vis,st,adj);
            }
        }
        st.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]){
        stack<int>st; //for storing the order
        vector<int> ans; // se nikal ke isme hi daalna hai 
        //visted array
        vector<int> vis(V,0);
        //for connected componets 
        for(int i = 0; i<V; i++){
            if(vis[i] == 0){
                dfs(i,vis, st, adj);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
