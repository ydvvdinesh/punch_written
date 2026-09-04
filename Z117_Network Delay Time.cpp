//maine khud kiya hai bina kisi help ke 
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Your code goes here
        //edges list to adjacncy list, directed 
        //vector<vector<pair<int,int>>> adj(n + 1);
        vector<pair<int,int>> adj[n + 1];
        for(auto it : times){
              adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n+1, 1e9);
        dist[k] =0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,k}); //distance k
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int distance = it.first;
            // traverse to neighbour 
            for(auto ti : adj[node]){
                int v = ti.first;
                int u = ti.second;//weight respective node ko
                if(distance + u < dist[v]){
                    dist[v] = distance + u;
                    pq.push({dist[v], v});
                }
            }
        }
    // find maximum time , between all the nodes , 
    //question asked minimum time btaoo jisme me k node se signal shuru hoke sab node ke pass khud pauch jaye, toh humne source se sabki shortest distance dist array me store karli , ab uss array me jis index / node ki value sabse se jaada mtlb utna tiume hai lga maximum tak pauchne me , toh woh minimum time hi hoga , usse kaam me nahi pauch skte kidr bhi 

    int maxi = 0;
    for(int i = 1; i<=n; i++){
        if(dist[i] == 1e9) return -1;
        maxi = max(maxi, dist[i]);
    }
    return maxi;
    }
};
