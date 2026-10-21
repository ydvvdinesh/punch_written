class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int n = nums.size();      
        int bxor = 0;
        //a xor a = 0
        // a xor 0 = a 
        for(int i = 0; i<n; i++){
            bxor = bxor ^ nums[i];
        }
        return bxor;
    }
};
