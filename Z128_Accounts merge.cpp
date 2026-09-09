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

//simple question hai bus code different hai , yadi do rmail same hai toh mtlb woh ek hi person hai toh unn mail ko ek mail me mereg kardo simple hai 
//we are using one map declare krenge  jo store krega sarting me konsi mail kisi node pe hai , humne har har ek bnde ko and uski node ko mail maang liya hai ,node 1 to jitne bnde honge 
// after edge, hum ek disjoint datadtructure bna lenge jisme yadi mail repeat kar rahi hai toh unko uss node se connect krenge jisme woh mail phele aayi thi aise uske ultimate parent last waale honge and , after everyline of code we write kon kya kar raha hai 

//1.create disjoint datastructure usse ultimate parent milega 
//2. now ultimate parent mil jayega , then merge kardenge , through use of map
//3. result ko return kar denge 

class Solution{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> accounts){
        int n = accounts.size();
        unordered_map<string, int> mapmailnode;
         // Disjoint Set data structure
        DisjointSet ds(n);
        // mapp consits of mail, which node me hai and map name mapmailnode
        //now traverse through the given list and put them into map
        for(int i = 0; i<n;i++){ // ye har row / node pe le jayegi in starting
            for(int j = 1; j<accounts[i].size();j++){ //why j starting froim 1 because o pe toh name hai , then email hai . details[i].size - means details ki usse row ki size tak jayeha 
                //now get the mail frist 
                string mail = accounts[i][j];
                //yadi map khali hai or If this mail was not already existing in map then put that mail into map 
                if(mapmailnode.find(mail) == mapmailnode.end()){
                mapmailnode[mail] = i;
                }
                else{ //already present hai toh woh node likhne ki zarrot nahi map woh unite ya connect kregi jisme wo mail phele se present hai usme 
                //new node, jisme phele aa chuki hai 
                ds.unionByRank(i, mapmailnode[mail]); //dono ke ultimate baap same ho chuke hai ab last me hum ultimate parent waali node me sab kuch daal denge 
                }
            }
        }
        // till now we put all the things into map, now we have to merge the mail , till now wejust connect it and put into mapp
        vector<string> mergedmail[n];
        //now move into map
        for(auto it : mapmailnode){
            string mail = it.first;
            //now hum woh node dekh rahe jisme hum woh bhejni hai mtlb ultimate parent 
            int node = ds.findUPar(it.second);
            mergedmail[node].push_back(mail);
        }
        // till noe we merged all the things 
        // now we have to store answer 
         vector<vector<string>> ans;
         //lets iterate all list of merged mail
         for(int i = 0; i<n;i++){
            /* If a person has no mails, 
            skip the iteration */
            if (mergedmail[i].size() == 0) 
                continue;
             // Otherwise, add all the merged mails of person 
            sort(mergedmail[i].begin(), mergedmail[i].end());
               vector<string> temp;
               temp.push_back(accounts[i][0]); //phele name push kardo 
                for (auto it : mergedmail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
         }
           return ans;
    }
};
