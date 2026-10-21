class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int XORR = 0;
        for (int i = 0; i < n; i++) {
            XORR = XORR ^ nums[i];
        }
        // this loops givs a number now we will look to the rightmost st bit and
        // on that basis we create two buckets , jiski rightmost bit 1 hogi woh
        // sab ek mai and jinke zero woh sab ek mai aayenge this will find the
        // rightmost bit
        // XORR contains XOR of the two unique numbers.
        // Find the rightmost set bit.
        int rightmost = (XORR & (XORR - 1))^XORR;
        int bucket1 = 0;
        int bucket2 = 0;
        for (int i = 0; i < n; i++) {
            // yadi 1 hai toh bucket one mai daalenge
            if ((nums[i] & rightmost) != 0) {
                bucket1 ^= nums[i]; //duplicate khud zero ho jayenge 
            
            } else {
                bucket2 ^= nums[i];
            }
        }
        // Return the result in sorted order
        if (bucket1 < bucket2) return {bucket1, bucket2};
        return {bucket2, bucket1};
    }
};
