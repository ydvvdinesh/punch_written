//better approach - isme generate hone ka wait nahi krte sidha aap application use kro 
//instead of generating the subarray first and then calculating product (3rd loop), we keep multiplying while expanding the subarray.
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i<n; i++){
            int prod = 1;
            for (int j = i; j<n; j++){
                prod = prod * nums[j];
                maxi = max(prod, maxi);
            }
        }
        return maxi;
    }
};
