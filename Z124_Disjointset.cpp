/*
Disjoint Set Union (DSU) is mainly used to connect and manage components/groups of a graph efficiently.
But more precisely:
What does DSU do?
DSU keeps track of which nodes belong to the same connected component.
It provides two main operations:
Find(x) → tells you which group/component x belongs to.
Union(x, y) → connects the groups containing x and y.
*/
//approach - step -1 find the ultimate parent of the given node 
//step -2 find the rank(not height , in magintude we say upper leaf node tak height) of ultimate parent of both nofr 
//step - 3 those have smaller rank went and  connect to larger rank
//lets solve for rank size toh same hi hai but size toal size dekhta , ki ultimate waale group me total node kitni hai 
class DisjointSet {
    vector<int> rank, parent, size; 
public:
    DisjointSet(int n) {
     rank.resize(n+1,0); // we deaclaration 0 at every place 
     parent.resize(n+1);
     size.resize(n+1,1); // size declarae with 1 
     for(int i = 0; i<n; i++){
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
            rank[ulti_u]++;
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
//path compression - is the way in which we directly connect evry node with the ultimate parent if that component 
