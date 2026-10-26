//ek dam easy bas thoda sa length - we have to find the minimum no of operation in mutilply given matrice by each other 
//how operation will be counted ? , matrix A = 10*90 , matrix b = 90*50 so the c will be 10*90*50  = 45000 operations
//now hume mutliple matrix diye honge hai sab multiply karne hai ek , toh aisi mutliplu krne jisse no of operation minimum aaye , woh hume mutliple option karke nikal denge like ABCD DIYA hai toh AB and CD , A and BCD aise saare possible way aayenge 
//dimension ke liye hume matrix diya hoga so we use arr[i-1] * arr[i] ye formula hai and humne isko drive kiya hai
//step -1 start with index i and end at j 
//step -2 parition 
class Solution{
	public:
    int func(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        // base 
        if(i == j) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //explore all parition parition , k is the pointer which break length og i and j into two parts 
        int mini  = 1e9;
        for(int k = i; k<j; k++){
            //number of operarion when two matric multiply + usko multiply hone mai jo beeche hue + and jp second part mai bhi hu hoge woh alg
            //ab * cd = a*b me bhi operation huye hai and same c and d ke time bhi huwe honge and last mai multiply ke tme bhi huwe honge , isliye unko bhi call karliye  
            int operation = (nums[i-1]*nums[k]*nums[j]) + func(i,k,nums,dp) + func(k+1,j,nums,dp) ;
            mini = min(operation,mini);
        }
        return dp[i][j] = mini;
    }
		int matrixMultiplication(vector<int>& nums){
            int n = nums.size();
            vector<vector<int>> dp(n, vector<int>(n, -1));
            //kyuki zeroth se compare bhi krwani hoti hai na 
            return func(1,n-1,nums,dp);
    	}
};
