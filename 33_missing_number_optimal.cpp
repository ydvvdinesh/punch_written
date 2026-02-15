//optimal approach 
//logic sum by formula and sum of each number of array (one by one)
//step-2 formula sum - each number sum = missing element
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int formula_sum = n*(n+1)/2;
        int each_sum=0;
        for (int i = 0; i < n; i++){
            each_sum = each_sum + nums[i];
        }
        return formula_sum - each_sum;
    }
};
