class DisjointSet {
public:
    /* To store the ranks, parents and 
    sizes of different set of vertices */
    vector<int> rank, parent, size;

    // Constructor
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // Function to find ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    // Function to implement union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Function to implement union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
}; 

/*
Traverse the list of stones to find the maximum row and column indices. This helps in defining the size of the Disjoint Set data structure.
Create a Disjoint Set data structure large enough to accommodate all rows and columns. Each row and column is treated as a separate node.
For each stone, treat its row and column as nodes and unite them using the union by size method. This ensures that stones sharing the same row or column are in the same connected component.
Use a map to keep track of unique nodes that have stones. This helps in counting distinct connected components.
Iterate through the unique nodes and count how many distinct components there are by finding the ultimate parent of each node.
The maximum number of stones that can be removed is the total number of stones minus the number of connected components.
Return the calculated number of stones that can be removed.
*/

// rows and column ko node bna do and then unka disjoint set bna do , ans = n- no fo connected coponents , connected cooponents disjoint set bta dega 
//question asking - jinke , row and column me woh akele bchenge 
//1. find maximum row and column kyuki woh ds ke time kaam aayega , hum real col + maxrows +1 krenge , cordinate mapping , then jis bhi row yaha column me hoga uska ultimate parent nikalenge toh jo stone row and column me that uska bhi wohi ultimate parent hoga 
class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // we are finding the maximum number where row and colum ended 
      int maxrow = 0;
      int maxcol = 0;
      //maximum of stone array
      for(auto it : stones){
        maxrow = max(maxrow, it[0]); // it[0] = row 
        maxcol = max(maxcol, it[1]); // it[1] = column of stone array 
      }

      // now create DisjointSet which declared the total number of row and columnn , yahi toh likha hai starting , column ko node bnana , row ke saath satth 
      DisjointSet ds(maxrow + maxcol+1); //1 to  prevent any conflicts

         // To store the nodes having a stone in Disjoint Set
        unordered_map<int, int> stonenodes;
        for(auto it : stones){ // lets iterate all stone 
        int noderow = it[0];
        int nodecol = it[1]+ maxrow + 1;
        //unnited two nodes
        ds.unionBySize(noderow, nodecol);
        stonenodes[noderow] = 1;
        stonenodes[nodecol] = 1;
        }

        int nc = 0; // jo ds me honge 
        //now iterate through unordered_map
        for(auto it : stonenodes){
            if(ds.findUPar(it.first) == it.first){
                nc++; 
                //ds me saare rhenge akele saath Increment the count if a new component is found
            }
        }
        return n-nc;
    }
    //after storing 
};
