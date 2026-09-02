class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
   //lets create the graph first graph or adjacen y list first so we use layter 
    vector<int> adj[N];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]); // one direction
        adj[it[1]].push_back(it[0]); // another direction
        // we say both direction because it is undirected graph that`s why we make this
    }
    //after creating graph or adjecncy list
    vector<int> dis(N, 1e9);
    dis[0] = 0;
    // distance of the source from the source is zero, In this problem statement, we have assumed the source vertex to be ‘0’.  
    //creating a distance vectpr which gonna store the distance of the node from the source 
    queue<pair<int,int>> q; //node, distance from the node 
    q.push({0,0});
    //source node and the distance from in

    // now jab q khaali na hi jaye tab tak chalte raho 
    while(!q.empty()){
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();

        for(auto it : adj[node]){
            if(dis[it] == 1e9){ //not visited hai 
                dis[it] = distance + 1;
                // yadi unvisted hai toh hum ye bol skte hai ki last me update krdo one who hi hoga  check ki jarrorrat hai hi nahi
                q.push({it, distance +1});
            }
        }

    }
    vector<int> ans(N,0);
    // yadi non visted hai toh usko  -1 de denge 
    for(int i = 0; i< N; i++){
        if(dis[i] == 1e9){
            ans[i] = -1;
        }
        else{
            ans[i] = dis[i];
        }
    }
    return ans;
    }
};
