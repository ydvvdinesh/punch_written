class Solution {
public:

    void dfs(int start_node, vector<vector<int>>& adj, vector<int>& vis){
        vis[start_node] = 1;
        //ab answer store nahi karn hum sirf traverse ke liye use kre rahe hai
        for(auto it : adj[start_node]){
            if(vis[it] == 0){
                dfs(it, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //adjacency matrix is given , we are changing it into adjacency list 
        int n = isConnected.size();
        vector<vector<int>> adjls(n);
        for(int i=0;i<n;i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        //here we created the ajadceny list , now we have to traverse and count the starting point of parts which is given . this parts is the component of graph
        int count =0; 
        //created visited array 
        vector<int> vis(n,0); // declaration of array , with declaring every thing as zero
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){ // its visited nahi hai toh visit kro that1s why we call dfs to visitthe complete compom=net
            count++;
                dfs(i,adjls,vis);
                //ye dfs ek componet ke saare node ko visit kardega , then woh array me mark ho jayenge then hum directly next component pe badh jayenge
            }
        }
        return count;
    }
};
