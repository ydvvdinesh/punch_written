//optimal approach
//logic = doing with xor , xor all give you remaining one
//2 properties and question over 
//p1- a^a = 0 , 0^a=a , xor of a and a is zero, xor of a and 0 is zero
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        int n = nums.size();
        for (int i = 0; i<n;i++){ //pure me iterate krwaya and using xor and woh khud answer de dega
            xorr = xorr^nums[i];
        }
        return xorr;
    }
};
