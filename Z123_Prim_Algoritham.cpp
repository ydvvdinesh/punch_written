//mst - a tree with n node and n-1 edges and everynode is reachable and minium mst - part of that tree with with minmum weight through which we can traverse to every node
//approach - 1. peheli node lo usko priority queue me daalo and then usko mark kro visted in visted array , 
//2. now to next operation - ab uske jitne adjcent hai unko queue and daalo and and har baar jo nikaloge pq se toh humesa minmum waala part phele bhar aayeha that give minimum weight ,jisko nikla yadi woh visted nahi hai toh usko sum naam ke variable me add krdo and mark it visted 
//pq will always select minimum weight toh khud hi minimum mst create hota chla jayega m, weight uska hi lena hai sum mai jo visted kiya ho 
//isme jo visted array ko ek step baad mark karna hai , phele q ko nikal ke usme operation lagna hai in starting baaki toh sab same hi hai 
class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       // Min-Heap to store pair of {edgeWt, node}
    priority_queue<
    pair<int,int>,        // What we store
    vector<pair<int,int>>, // Internal container
    greater<pair<int,int>> // Comparator
    > pq;
        // parent ko jab store karna hota hai jab mst return krna ho yaha sirf sum return karna hai 
        vector<int> vis(V,0);
        // declaration of the vector with number 0 of size variable V
        // push the first node in the queue, abhi hume vis array ko nahi touch karna woh tabhi hoga , jab pq hum ek pair bhar degi tab 
        pq.push({0,0}); // weight, node 
        int sum = 0; // sum har baar reset nahi hoga ek baar me hi store hota jayega 
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            // yaha node bahar nikal di hai and usko phele hi humne reserve kar diya tha, now use that value
            int node = it.second;
            int wt = it.first; // weight jab adjacent pe gaye toh uska 
            //queue se node bahar nikal chuki hai ab vis pe operation krneh
            //yadi already array visted hai toh hum uska sum ya push kuch nahi krenge hum uss node ko neglect kar denge
            if(vis[node] == 1) continue;
            //ye dusre node ye start honge generally
            vis[node] = 1; //and jisko visit kiya ussi ka sum me wt add krenge ye obviuous hai
            sum += wt;
            // now went to adacent node 
            for(auto ti : adj[node]){
                int v = ti[0]; // node
                int u = ti[1]; // weight
                if(vis[v] == 0){
                    pq.push({u,v});
                }
            }

        }
        return sum;
    }
};
