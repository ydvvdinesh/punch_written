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

//no of the islands - count 
//step -1 put land all the given corrdinates and then after puting in the array we will mark it visit and we look for the neighbour if negihbiur are there that means woh ek hi component ho jayenge , so we reduce the count of no of connected land/ nof of indviually land by the number jitni neighbour visited (but neighbour khud connect nahi hone chyiye with number oth wise us hisab se vcount hoga)
//step 2 - yadi neighbour nahi hai mtkb alag jagahai then count them 

//and jab bhi neighbour visit honge mtkb pass hinge toh woh ek hi component ki trah treat honge , so usko connect karne ke liye we have only one data structure which is disjoint 
//for making the 2d every place as node we row*m + col
class Solution{
public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        // Disjoint set Data structure
        DisjointSet ds(n * m);
        // To store the result
        vector<int> ans;
        // now iterate thorugh given coordinates 
        for(auto it : A){
            int row = it[0];
            int col = it[1];
            // yadi already visited hai 
            if(vis[row][col] == 1){
            ans.push_back(cnt);
            continue;
            }//toh kuch mat kro 
            // other wise mark them visited and jab jisko mark kiya visited waaha land bhi aayega so increase the count of indviual componet
            vis[row][col] = 1;
            cnt++;

        //jab place hiona start ho jaye then look for the neighbour
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        //now traverse to all direction
        for(int i = 0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            //index ke place ko kuch number dene ka time aagaya hai 
            int node = row*m + col; // ye jis node pe hum khade hai 
            //and jab neighbour traverse krenge toh hume , value dercrease hi karni hai yadi connected componenet hai toh so we want ki ki side waali node visited hi mile 
            if(nrow<n && nrow>=0 && ncol<m && ncol>= 0 && vis[nrow][ncol] == 1){
                //yadi side waali and current ke ultimate parent , yaha connected nahi hai toh , but visted hai as mentioned in upper statement toh decrease the things 
                int adjnode = nrow*m  + ncol; // neighbour waali node 
                if(ds.findUPar(node) != ds.findUPar(adjnode)){
                    cnt--;
                     // Perform the union
                        ds.unionBySize(node, adjnode);
                }
            }
        }    
            ans.push_back(cnt);
        }
        return ans;
    }
};
