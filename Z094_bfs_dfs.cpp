class Solution {
  public:

  void dfs(int node, vector<vector<int>> edges, vector<int>& vis, vector<int>& ls){
    vis[node] = 1;
    ls.push_back(node);
    // traverse all the neghbour in down ward form
    for(auto it : edges[node]){
        if(vis[it] == 0){
            dfs(it,edges, vis, ls);
        }
    }
  }

    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
     vector<int> vis(V,0);
      vector<int> ans;
      int start =0;
      dfs(start, edges, vis, ans);
      return ans;
    }
    
    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) {
        vector<int> vis(V, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // now every neighbour
            for(auto it : edges[node])
            if(vis[it] == 0){
                vis[it] = 1;
                q.push(it);
            }
        }
        return ans;
    }
};
