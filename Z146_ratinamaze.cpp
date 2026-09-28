//question - start from 0,0 to n-1, n-1 tell me all paths ja se ja skate hai woh , cell repeat ho skati hai exact paath nnahi
//hum sirf ussi cell pe ja skate hai jaha 1 ho 
//approach - hum 4 direction me jaa skate hai jaha 1 hoga usse pe , so ek cell pe gaye and dekhnge ki hum kidr jaa skte hai waaha jayenge aise karke saare possible way try krenge 
class Solution{
    public:

    void f(int i, int j, string path, vector<vector<int>> &grid, vector<string> &ans){
        int n = grid.size(); //row and column same hai toh kisi ke lelo
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        
        //but jisko hum traverse kar denge toh usko hum zero khenege baad me usko 1 kar denege har, ji se dussre ko traverse na karle
        grid[i][j] = 0;
        
        //yadi upper waala liya toh 
        if(i-1>=0 && grid[i-1][j] == 1){
            path.push_back('U');
            f(i-1,j,path,grid,ans);
            path.pop_back();
        }
        //down
        if(i+1<n && grid[i+1][j] == 1){
            path.push_back('D');
            f(i+1,j,path,grid,ans);
            path.pop_back();
        }
        //left 
        if(j-1>=0 && grid[i][j-1] == 1){
            path.push_back('L');
            f(i,j-1,path,grid,ans);
            path.pop_back();
        }
        //right
        if(j+1<n && grid[i][j+1] == 1){
            path.push_back('R');
            f(i,j+1,path,grid,ans);
            path.pop_back();
        }
        //JAB operation ho jaye toh jaise tha usko vaise kardo next recursive call me kaam aayega
        grid[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int> > &grid) {
        int n = grid.size();
        string path;
        vector<string> ans;
        //starting and ending point dono hi zero hai toh kaam kaha se shuru karenge 
        if(grid[0][0] == 0 || grid[n-1][n-1] == 0){
            //return empty string
            return {};
        }

        //function call 
        f(0, 0, path, grid, ans);
        //else return 
        return ans;
    }
};
