class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for (int i = 0;i<n;i++){
            int sum =0;
            for (int j = i;j<n;j++){
                sum = sum + nums[j]; 
            if (sum == k){ // har baar sum check hoga jaise hi sum qual huwa mtlb we get our subarray what ever we want
                count ++; // no of sub array
                // len = max(len,j-i+1) // length of the longest subarray
            }
            }
        }
        return count;
    }
};
