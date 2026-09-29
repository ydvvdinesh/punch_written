
class Solution {
public:

    // Function batayega ki current node par given color
    // place kar sakte hain ya nahi
    bool ispossible(int num, int node, vector<int>& colors, vector<int> adj[]) {

        // node ke saare adjacent nodes check karo
        for (int i = 0; i < adj[node].size(); i++) {

            int adjnode = adj[node][i];

            // Agar adjacent node ka color same hai
            // toh current node ko ye color nahi de sakte
            if (colors[adjnode] == num) {
                return false;
            }
        }

        // Koi adjacent node same color ka nahi mila
        return true;
    }


    // Recursive function
    bool f(int node, vector<int>& color, vector<int> adj[], int m, int n) {

        // Saare nodes ko color kar diya
        if (node == n) {
            return true;
        }

        // Har possible color try karo
        // 0th color, 1st color, 2nd color...
        for (int num = 0; num < m; num++) {

            // Pehle check karo ki ye color current node par
            // place kar sakte hain ya nahi
            if (ispossible(num, node, color, adj) == true) {

                // Current node ko color de do
                color[node] = num;

                // Ab next node ko color karne jao
                bool val = f(node + 1, color, adj, m, n);

                // Agar complete valid coloring mil gayi
                if (val == true) {
                    return true;
                }

                // Backtracking:
                // Ye color kaam nahi kiya,
                // toh current node ko uncolor karo
                color[node] = 0;
            }
        }

        // Koi bhi color kaam nahi kiya
        return false;
    }


    bool graphColoring(vector<vector<int>>& edges, int m, int n) {

        // Adjacency list
        vector<int> adj[n];

        // Undirected graph
        for (int i = 0; i < edges.size(); i++) {

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        // Initially kisi node ko color nahi diya
        vector<int> colors(n, -
        1);

        // Node 0 se coloring start karo
        return f(0, colors, adj, m, n);
    }
};


