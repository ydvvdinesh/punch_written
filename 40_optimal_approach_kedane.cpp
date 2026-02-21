//#optimal approach - kedane algo 
// har element ko iterate kro , do cheeze saath leke chlo one is sum and max at that particular point, and jaise hi sum < 0 ho toh sum ko reinitlize kro zero pe 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
    // iteration
    for (int i=0; i<n; i++){
        sum = sum +nums[i];
        //har element pe maximum ka count rakhega 
        maxi = max(maxi, sum);
        if (sum < 0 ){
            sum = 0;
        }
    }
    return maxi;
    }
};
