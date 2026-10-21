class Solution {
public:
    int singleNumber(vector<int>& nums) {        
        int n = nums.size();
       // if not in two then one mai lie krega
       //if not in one then only in two , ek mai hi hogi
       int ones = 0;
       int twos = 0;
       for(int i = 0; i<n; i++){
        // condition 1 , jab dono clauses ek saath sahi honge tabhi hi one me aajayega 
         ones = (ones^nums[i])&(~twos);
         //two mai tabhi hoga jab one mai nahi hoga 
         twos = (twos^nums[i])&(~ones);
       }
       return ones;
    }
};
