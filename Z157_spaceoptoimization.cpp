//ek dum easy hai - starring point fix hai alice and bob ke so , unke last me pauchne with maximum sum , but ek condition dono ek saath move krenge bus ek dum easy, naam ka hard hai
//we are doing recurison from 0 or from the fixed starting point 
// jab bhi starting mai fixed diya hai toh hum wahi se start krenge  
class Solution {
public:
    // ek hi i , kyuki dono ek saath chalenge in row and alice column, bob column , because alice and bob ke pass 3 option hai konse column mai jaana chate hai as mentioned in the question
    /*int func(int i, int j1, int j2, vector<vector<int>>& matrix, vector<vector<vector<int>>>& dp){
        int n = matrix.size(); //row
        int m = matrix[0].size(); // columns
        //out of bound option
        if(j1<0 || j2<0 || j1>=m || j2>=m){
            return -1e8;
        }
        //now base case we reached to the last row then mu;tiple columns is there kaha jayenge
        if(i == n-1){
            //yadi toh ek pe pauche toh ek baar count karenge 
            if(j1 == j2){
                return matrix[n-1][j1];
            }
            //yadi same nahi toh dono lenge
            else{
                return matrix[n-1][j1] + matrix[n-1][j2];
            }
        }
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        // now we will explore the paths but remebr more 1 move of alice bob have 3 option to choose , so total possible is 9 because for every next move we can go to j-1, j , j+ that means -1 to 1
        int maxi = INT_MIN;
        for(int d1 = -1; d1<=1; d1++){
            for(int d2 = -1; d2<=1; d2++){
                int value = 0;
                if(j1 == j2){
                     value = matrix[i][j1];
                }
                else{
                     value = matrix[i][j1] + matrix[i][j2];
                }
                //move t next and try every thing
                value += func(i+1, j1+d1, j2+d2, matrix, dp);
                maxi = max(value,maxi);
            }
        }
        return dp[i][j1][j2] = maxi;
    }*/

    //its opposite to recursion because its tabluation we will start from n-2 to go till zero 
    /*int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size(); //row
        int m = matrix[0].size(); // columns
        // Initialize a 3D DP array to store computed results
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        //out of bound waali problem during runtime dekhte hai 
        //base case 
            for(int j1 = 0; j1<m; j1++){
                for(int j2 = 0; j2<m; j2++){
                    if(j1 == j2){
                        dp[n-1][j1][j2] = matrix[n-1][j1];
                    }
                    else{
                        dp[n-1][j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
                    }
                }
            }

        // now we have to do operations all 1 step how much option

        for(int i = n-2; i>= 0; i--){
            for(int j1 = 0; j1<m; j1++){ //columns mai toh aise hi move krege na
                for(int j2 = 0; j2<m; j2++){
                    int maxi = -1e8;
                    // now har ki saari condition dekhni hai 
                    for(int dj1 = -1; dj1<=1; dj1++){
                        for(int dj2 = -1; dj2<=1; dj2++){
                            int value = 0;
                            if(j1 == j2){
                                 value = matrix[i][j1];
                            }
                            else{
                                value = matrix[i][j1] + matrix[i][j2];
                            }
                            // now check the upper and lower bound
                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
                                value += dp[i+1][j1+dj1][j2+dj2];
                            }
                            else{
                                value = -1e8;
                            }
                            maxi = max(maxi,value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }*/

//iska makasd hai dp array htane ka 
    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size(); //row
        int m = matrix[0].size(); // columns
        // Initialize a 3D DP array to store computed results
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        //for space optimaztion use the 2d array this time 
        vector<vector<int>> front(m,vector<int>(m,0)); //aage waala 
        vector<vector<int>> curr(m,vector<int>(m,0)); // abhi jo chal raha hai
        //out of bound waali problem during runtime dekhte hai 
        //base case 
            for(int j1 = 0; j1<m; j1++){
                for(int j2 = 0; j2<m; j2++){
                    if(j1 == j2){
                        front[j1][j2] = matrix[n-1][j1];
                    }
                    else{
                        front[j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
                    }
                }
            }

        // now we have to do operations all 1 step how much option

        for(int i = n-2; i>= 0; i--){
            for(int j1 = 0; j1<m; j1++){ //columns mai toh aise hi move krege na
                for(int j2 = 0; j2<m; j2++){
                    int maxi = -1e8;
                    // now har ki saari condition dekhni hai 
                    for(int dj1 = -1; dj1<=1; dj1++){
                        for(int dj2 = -1; dj2<=1; dj2++){
                            int value = 0;
                            if(j1 == j2){
                                 value = matrix[i][j1];
                            }
                            else{
                                value = matrix[i][j1] + matrix[i][j2];
                            }
                            // now check the upper and lower bound
                            if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m){
                                value += front[j1+dj1][j2+dj2];
                            }
                            else{
                                value = -1e8;
                            }
                            maxi = max(maxi,value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][m - 1];
    }
};
