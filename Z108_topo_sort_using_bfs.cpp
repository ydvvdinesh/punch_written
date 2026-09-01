//using bfs 
//aproach - create a indegree graph fill it , then jiski indegree 0 hai usko queue me daalo sabse phele 
//2. jaise hi uss node ko daalo toh usse negbiour , jinpe woh impact daal rahi hai , jinkiin degree woh incrase kar hai hai unki indegree -1 krdo array me , jaise hi hojaye toh queue me daal do aise hi answer mil jayega
class Solution{
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> indegree(V,0);
        // declare a indegree vector with 0
        for(int i =0; i<V; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        //filling up the indegree array with the indegree given in the graph , fix them 

        queue<int>q;
        //now jinki indegree zero unko push to queue
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo; // to store answer 
        //now bfs 
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            //ab jaise hi remove ki toh degree reduced bhi karni hai 
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
};
