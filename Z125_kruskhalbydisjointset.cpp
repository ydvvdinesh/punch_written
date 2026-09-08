//now disjoint data structure bnana hai , by rank bnayenge 
class Disjoint{
    vector<int> parent, rank;
public: 
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }
    // now path compression path , pote , beta data , sabka dada se direct contact
    //ye node ka ultimate parent de dega
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionbyrank(int u, int v){
        int ultiu = findUPar(u);
        int ultiv = findUPar(v);
        if(ultiu == ultiv) return;
        //now rank jiski usko dusre me connect kardo
        if(rank[ultiu] < rank[ultiv]){
            parent[ultiu] = ultiv;
        }
        else if(rank[ultiu] > rank[ultiv]){
            parent[ultiv] = ultiu;
        }
        else{
             parent[ultiu] = ultiv;
             //sirf rank tabhi badhani jab equal ho otherwise jiski badi uski hi aayegi
             rank[ultiu]++;
        }
    }
};

//kruskal`s algo
//1. sort all weights
//2. and minimum weights waalo ko add krte jaoo , isliye hum disjoint set ka use krenge , it goonna creaate the mst using union function 
//how disjoint working in krushkal - kuch node given hogi as from of graph we write all and every one parent is their own and then and hum dono krte jayeneg and yadi unke ultimate parent dekheneg using fundUpar function , jiske bhi same nahi honge mtlb woh phele se connected nahi hai toh unke weight ko count krenge , or duri language me bole toh unko connect kardenge 
//jinke baap ek mile unka wright count nahi karna kyuki unpe toh hum already reach kar chuke hai 
class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       vector<pair<int,pair<int,int>>> edges; // weight , node1(u) , node2(v);
        // this array is going to store the all in a pair 
        //convert edges from the adcency list for all node 
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                int v = it[0]; // adjacy me pheli node hoti hai then baaki kuch
                int wt = it[1];
                int u = i; //node1 or u
                edges.push_back({wt,{u,v}});
            }
        }

        //now edges created noe we have to sort it 
        sort(edges.begin(), edges.end());
        //create doisjoint data structure 
        Disjoint ds(V);
        //after sorting ab check karna hai connectes hai ki nahi 
        int mst = 0;
        for(auto it : edges){
            // ab vector me nikal ke 
            int node1 = it.second.first;
            int node2 = it.second.second;
            int weight = it.first;

            //ab ultimate parent check karne hai 
            // ds - disjoint data structure
            if(ds.findUPar(node1) != ds.findUPar(node2)){
                // yadi ek baap nahi hai toh ek baap bnaooo
                mst += weight;
                //now tconnect the nodes 
                ds.unionbyrank(node1, node2);
            }
        }
        return mst;
    }
};
