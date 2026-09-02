//same shortest distance hi batani hai in dag 
//approach 1. find the topo sort woh ek order dega , jo stack me store hohga 
//2. stack ke top ko nikal  , usse source se distance dekhte jaoo and distance array me store kardo and remeber assign karne ke baad yadi usse chota distance miltance toh hi replace karna otherwise wohi rhne dena
class Solution {
    private:
    
    void dfs(int node, vector<int>& vis, vector<pair<int,int>> adj[], stack<int>& st){
        vis[node] = 1;
        //after marking visitng f=dfs call hota jayega and stack me tabhi jayyegi jab haar node ke pass koi aage traverse karne waala nahi hoga
        for(auto it: adj[node]){
            int v = it.first;
            if(vis[v] == 0){
                dfs(v, vis,adj, st);
            }
        } 
        st.push(node);
    }

    public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {
        // lets create graph or adjacency list 
        vector<pair<int,int>> adj[N];
        for(int i = 0; i< M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2]; //[2]
            adj[u].push_back({v,wt}); //dono aayenge in directed kyuki weight bhi saath u ->{v,wt}
            //and directed hai so isliye ek hi aayega naaki 2 aayenge 
        }
        //lets do topo sort 
        stack<int> st;
        vector<int> vis(N,0);
        for(int i = 0; i<N; i++){
            if(vis[i] == 0){
                //call dfs, woh traverse and stack me cheeze store kar lega
                dfs(i, vis, adj,st);
            }
        }

        //now topo sort ho gaya , rexaling the edge time , isme kuch hai simple hai daata structre se node nikalenge with uska respective distance ke saath and uske jitne bhi neghibour honge , unke wight ke saath current ka weight add krenge and yadi woh weight/ distance chota hai jo distance array me present hai toh usse replace krenge otherwise same rakhenege aise karke hume direct value milegi and last woh distance array return kar denge
        vector<int> dis(N,1e9);
        dis[0] = 0;
        //step 2 started jab tak stack khaali na ho lage raho
        while(!st.empty()){
            int node = st.top();//it gives value of node 
            st.pop();
            for(auto it : adj[node]){ //usse node ke saare neighbour one by one aayenge
            //node toh ek hi hai but woh jin se connected hai mtlb unke neighbour woh khud bhi and unke weight bhi hai 
            int v = it.first;
            int wt = it.second;
            if(dis[node] + wt < dis[v]){
                dis[v] = dis[node]+wt;
            }
            }
        }
          for (int i = 0; i < N; i++) {
            if (dis[i] == 1e9) 
                dis[i] = -1;
        }
        return dis;
    }
};

