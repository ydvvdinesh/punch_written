//bipartite - hum color krenge 0 or 1 se toh kis bhi adajcent nodes me complete graph pe same color naahi hoga
class Solution {
    bool Bipartite(int start, vector<vector<int>>& graph,vector<int>& color){
        int n = graph.size();
        queue<int> q;
        //pushing the first node in the queue 
        q.push(start);
        //now color that node to 0 in starting'
        color[start] = 0;
        //color is the vector which storing the color of the all the node which is given by me
        //now to queue

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(color[it] == -1){
                    //ya -1 se isliye check karwa rhahe kyuki hum main function ke color me sabme -1 hi daalenege , jab ye function call hoga toh automatically -1 hi khaali jagah ke liye istemal hogi
                    //yadi koi color nahi huwa hai color node pe
                    //toh uska opposite color kardo
                    color[it] = !color[node]; 
                    q.push(it);
                    //color karke push kardo
                }
                else{ // color ho chuka hai phele se then check for ki same toh nahi
                    if(color[it] == color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

//ye ek hi function me ho skta that but connected component ka bhi dhyan rakhna hota hai 
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //now declare vector of color and intiliaze with -1 
        vector<int> color(n,-1);
        for(int i = 0; i<n; i++){
            //i se start krengenaki zero se , kyuki zero usme aa chuka hoga
            // Only start BFS for an unvisited component
            if(color[i] == -1){
                if(Bipartite(i, graph, color) == false){ 
                    return false; 
                }
            }
        }
    return true;
    }
};
