//longest common subsequence - dono dtring me jo common longest equence ki length deni hai 
class Solution {
   public:
    int func(int ind1, int ind2,string str1, string str2, vector<vector<int>>& dp) {
        //base condition
        // yadi dono index -ve hoga that means toh wahi hum zero return kar denge
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        //yadi dono index matches karke tat means hum usko apne subsequence mai lenge , toh isko 1 count krenge
        //and jab matche higa toh next index me jayenge uska check karne isliye dono index mai minus 1 hoga
        if(str1[ind1] == str2[ind2]){
            return dp[ind1][ind2] = 1 + func(ind1-1,ind2-1,str1,str2,dp);
        }
        //yadi match nahi krega krega toh do part mai split hoga ek baar ek index ko rok na hai and dusre ko move karna hai and dusre me phele index ko rok ke dusre ko move karna hai , last mai split waalo ka maximum return kar dena , jab match nahi kar raha toh 0 nahi hoga  
        return dp[ind1][ind2] = 0 + max(func(ind1,ind2-1,str1,str2,dp), func(ind1-1,ind2,str1,str2,dp));
    }

    int lcs(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return func(n1-1,n2-1,str1,str2,dp);
    }
};
