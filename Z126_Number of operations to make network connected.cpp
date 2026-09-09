class DisjointSet {
public:
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
     rank.resize(n+1,0); // we deaclaration 0 at every place 
     parent.resize(n+1);
     size.resize(n+1,1); // size declarae with 1 
     for(int i = 0; i<=n; i++){
        parent[i] = i;
     }
    }

    // path compression
    int findUPar(int node){
         if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }


    bool find(int u, int v) {
         return findUPar(u) == findUPar(v);
    }

    void unionByRank(int u, int v) {
     int ulti_u = findUPar(u); // find the ultimate parent of u and stored in ulti_u
     int ulti_v = findUPar(v); // find the ultimate parent of v and stored in ulti_v
    // Return if ulti_v already belong to the same component
    if (ulti_u == ulti_v) return;
    // now find rank and connect 
    if(rank[ulti_u] < rank[ulti_v]){
        parent[ulti_u] = ulti_v; // u connect to v 
    }
    else if(rank[ulti_u] > rank[ulti_v]){
        parent[ulti_v] = ulti_u; //v went and connect to u;
    }
    else{ //same rank toh kisi bhi connect kardo and , rank ko ek increase krdo upper isliye nahi ki kyuki hume jo bda hai uski rank hi highest chlegi kyuki connect hone ke baad woh us height se jada nahi jayega
        parent[ulti_v] = ulti_u; 
        // Update the rank
            rank[ulti_v]++;
    }
    }
    //same code aayega bus isme hum size ginte hai hai , jitne node connec honge utne size bdega 
    void unionBySize(int u, int v) {
        int ulti_u = findUPar(u); // find the ultimate parent of u and stored in ulti_u
     int ulti_v = findUPar(v); // find the ultimate parent of v and stored in ulti_v
    // Return if nodes already belong to the same component
    if (ulti_u == ulti_v) return;
    // now find rank and connect 
    if(size[ulti_u] < size[ulti_v]){
        parent[ulti_u] = ulti_v; // u connect to v 
        size[ulti_v] += size[ulti_u];
    }
    
    else{ 
        parent[ulti_v] = ulti_u; 
           // Update the size
            size[ulti_u] += size[ulti_v];
    }
    }
};
//yadi n connected componets diye hai so we require n-1 edges to connect them , but there is one catch we cannot use no of provinces -1 here because , we din`t have to use the edges from outside i hvae to use from the graph, nc is the no of connected components
//so now we gonna count extra edges, how ? we use the disjoint data structure, we write all the edges , then we check kiske ultimate parent same hai yadi same hai , mtlb woh ussi graph ka hissa and toh woh extra count ka hissa hogi, and same nahi hai toh , usko hum connect karte jayenge, yadi extraedges > nc-1 , toh ans nc-1 rhega because humne extra edge use krehai connect karne me and otherwise 1 use kiya 
class Solution{
public:
    int solve(int n, vector<vector<int>> &Edge){
        DisjointSet ds(n); // declaraation of disjoint data structure
        int extraedges = 0;
        for(auto it : Edge){
            int u = it[0]; // u is the node , edgesvector consit of node , it is not a adjancy lis
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){ // dono ke ultimate parent same hai mtlb connected hai 
                extraedges++;
            }
            else{ //yadi alag toh connected them 
                ds.unionByRank(u,v);
            }
        }
        //till this loop we have a data of total extra edges and we also connect them so smae nahi the 
        // now we have count no ofcomponents , so in disjoint set jo khud ka baap khud hai , mtlb woh hi ultimate boss hai usse component ka , so parent array me index and valuejiski same hai unhe count kro utne hi compomnets honge
        int nc = 0;
        for(int i = 0;i <n; i++){
            if(ds.parent[i] == i){
                nc++;
            }
        }
        int ans = nc-1;
        if(extraedges >= ans) return ans;
        return -1;
    }
};
// dosjoint pura gaand faad aata hai 
