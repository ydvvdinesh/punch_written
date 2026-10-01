int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i = 0; i<m; i++){
            vector<int> curr(n,0); // ye upper wali row jaha iterate krenge waaki so 
            for(int j =0; j<n; j++){
                if(i==0 && j==0){
                    curr[j] = 1;
                    continue; //kyuki row same hi rhegi 
                }
                int up = 0;
                int left = 0;
    //up jayenge jab row decrease karni hi hoti hai but yaha hume upper waali row ko vector me rakh liya 
                if (i > 0){
                up = prev[j];
                }
                if(j>0){
                    left = curr[j - 1];
                }
                curr[j] = up +left;
            }
                prev = curr;
        }
            return prev[n - 1];
    }
