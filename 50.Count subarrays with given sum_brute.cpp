//brute approach complete thing
/*
First loop → This chooses the start of the subarray.
Second loop →This chooses the end of the subarray.
Third loop (k loop) → This loop actually computes sumof that subarray.
What happens here
i → start of subarray
j → end of subarray
k → goes inside the subarray to compute the sum
and in better approach we are not going inside subarray we just add to previous sum
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for (int i =0; i<n; i++){
            for (int j =i;j<n;j++){
                int sum = 0;
                for (int x = i; x<=j; x++){
                    sum = sum + nums[x];
                    }
                    if(sum == k){
                        count++;
                    }
            }
        }
        return count;
    }
};
