//bruteforce - 3 loop chlaoo phele aache se saare array generate kro amd them uspe process kro 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i<n; i++){
            for (int j =i; j<n; j++){
                int prod = 1;
                for (int k = i; k<=j;k++){ // ye loop phele acche se generate hone degi usme pe kaam chalega
                prod = prod * nums[k];
                maxi = max(maxi,prod);
                }
            }
        }
        return maxi;
    }
};
