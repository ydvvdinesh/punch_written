//brute force 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n = nums.size();
       int maxi = INT_MIN;
       for (int i =0 ; i<n; i++){ // ye loop array iterate krwayega
        for (int j =i; j<n; j++){ // ye loop har element ke saare case legi 
            int sum = 0;
            for (int k = i ; k<= j ; k++){
                sum = sum + nums[k];
                maxi= max(sum,maxi);
            }
        }
       } 
       return maxi;
    }
};
//o(n3) - time complexity is very large
