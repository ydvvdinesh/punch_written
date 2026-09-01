//problem - chlo toh terminal node me pauch gaye toh aap safe node ho
//terminal node me tabhi pauche skte jab aap kisi loop me na faso , toh we are goint to 9traverse all the graph using dfs and ja bhi cycle uske node safe node nahi hongi , otherwise mostely hongi hi 
//path vis jab vist krenge toh 1 and jab waa sevapis aayenge toh usko 0 krke aayenge , yadi woh 1 and dobara bhi 1 karne ki kosis ki ja rahi hai toh cycle hai bro
class Solution {
public:

    // function to travserse and detect the cycle
    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& graph, vector<int>& check){
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0; // check node zero matalb hume ab tak safe node nahi mili hai 
        for(auto it: graph[node]){
            if(vis[it] == 0){
                if(dfs(it, vis, pathvis, graph,check) == true){
                    check[node] = 0; // yadi cycle mil gayi toh check node nahi mili hai na 
                    return true;
                }
            }
            else if(pathvis[it] == 1){ // 1 hai phir se one aagaya 
                check[node] = 0; // yadi cycle mil gayi toh check node nahi mili hai na 
                return true;
            }

        }
        pathvis[node] = 0; // yadi cycle nahi and return kar gaya aise hi toh , path vis ko zero kardo next ke liye phir checkk krenge 
        //yadi uppper kuch return nahi huwa hai mtlb koi cycle nahi mili toh hum false return karne ja rahe hai , but usse phele ek imp cheez hume bhi safe node mil gayi hai kyuki safe node sirf tabhi nahi milti jab cycle , otehr wise toh terminal tak move  krega hi nahi
        check[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                dfs(i,vis,pathvis,graph, check); // visited nahi toh har baar dfs call hoga, result check vector dekh lega ,woh store karta jayega 0 or 1 , 0 mtlb safe node nahi mili 1 mtlb mil gayi
            }
        }
        // To store the result
		vector<int> ans;

        for(int i = 0; i<n; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
