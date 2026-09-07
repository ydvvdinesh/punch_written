//main concept - har node har ke thorugh trarvse kregei, brute force algoritham waali cheez hai 
//dis[i][j] - distance between i and j,
//dis[i][k] = distance between i node and k node 
//k is the node we are representing jiske thorugh hum via jayenge between starting and ending 
//dis[i][j] = dis[i][k] + dis[k][j], distance from i to j but we are going through a node k ,
//approach - hum ek adjacency matrix bnaye, jisme woh usse node thprugh hi jayega humne specific ki hai , like i to j jaana hai par har baar k thorugh jaana hai 0 to n -1 tak jayenge toh , har baar hum jab caluclate karenge toh woh k node aayegi haar , k hum change karnte jaayenge jitni node node honge utna  
//ye neagtive cycle bhi detect krta hai , yadi matrix[i][j] ke time total path ki value negative gayi 
class Solution {
public:
	void shortestDistance(vector<vector<int>>&matrix) {
	int n = matrix.size();

    //ye sirf edge case yadi -1 toh usko infinte kro 
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 1e9;
            }
        }
    }

    for(int k = 0; k<n; k++){ // k is the via node jiske thorugh toh jaana hi pdega jab i to j jaoo 4
        for (int i =0; i<n; i++){ // i is the starting point
            for(int j = 0; j<n; j++){
                //har traversal ke baad tabhi replace karne jab minimum ho 
                matrix[i][j] = min( matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    //after traversing complete infinte hi raha toh toh mtlb koi dges nahi retur -1 as stated in wquestion
     for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(matrix[i][j] == 1e9){ // yadi a
                matrix[i][j] = -1;
            }
        }
     }
	}
};
