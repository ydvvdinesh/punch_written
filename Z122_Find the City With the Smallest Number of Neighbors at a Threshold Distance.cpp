class Solution {
public:
	int findCity(int n, int m, vector<vector<int>>& edges,
	             int distanceThreshold) {
		
        // 2d vector storing the result of flyod warshall 
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto it : edges){
            dist[it[0]][it[1]] = it[2]; 
            dist[it[1]][it[0]] = it[2];
        }
        //filling diagonal
        for(int i =0; i<n; i++){
            dist[i][i] = 0;
        }
        for(int k = 0; k<n; k++){
            for(int i = 0; i< n; i++){
                for(int j = 0; j<n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int citytravel = n;
        int citycnt = -1;
        for(int i = 0; i< n; i++){ // currreny city loop 
            int cnt = 0; //count kitini city trabel ki under threshold
            for(int j = 0; j<n; j++){ // adjacent node ginne ke lkiye loop , colum pe jo uske rspect ki loop 
                if(dist[i][j] <= distanceThreshold){
                    cnt++;
                } 
            }
            if(cnt <= citytravel){
                    citytravel = cnt; // we have to return the city tavel the minimum city if two city are same then then on absoulte number 
                    citycnt = i; // ye hi jo theshold ke under minim chal rahi hai 
                }
        }
        return citycnt;
	}
};
