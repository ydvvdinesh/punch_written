//yadi previs waale me one hai aur yaadi aapne dobara vist krne ki osis ki mtlb ek aur one aaye toh , cycle bn gayi ja se chla waah aagaya 
class Solution {
public:

    // function to traverse
    bool dfscheck(int node, vector<int>& vis, vector<int>& previs,vector<vector<int>>& prerequisites, vector<int>& ans){
        vis[node] = 1;
        previs[node] = 1;
        for(auto it : prerequisites[node]){
            if(vis[it] == 0){
                // yadi visit nahi toh visted krwaao dfs ko call karke
                if(dfscheck(it,vis,previs, prerequisites, ans) == true){
                    return true;
                };
            }
            //yadi visited hai and dobara previs 1 hai toh true return kardo
            else if(previs[it] == 1){
                return true;
            }
        }
        // yadi saara traverse kar liye and cycle nahi il nai toh backtrack krenge and last tak pauchenege , jo jab backtrack ho toh jinhe 1 kiya tha unko zero kar dena 
        previs[node] = 0;

        // we have to give them answer 
        ans.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // First convert prerequisites into adjacency list 
        vector<vector<int>> adj(numCourses); 
        for(auto it : prerequisites){ 
            int course = it[0]; 
            int prerequisite = it[1]; 
            adj[prerequisite].push_back(course); 
        }

        vector<int> vis(numCourses,0);
        vector<int> previs(numCourses,0);
        vector<int> ans;
        for(int i = 0; i<numCourses; i++){
            if(vis[i] == 0){
                if(dfscheck(i, vis, previs, adj, ans) == true){
                    return {};
                }
            }
        }
        // DFS gives reverse topological order 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
