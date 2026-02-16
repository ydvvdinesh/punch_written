class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        int len = 0;

        while (j < n) {

            sum = sum + nums[j];   // 1️⃣ expand window

            while (i <= j && sum > k) {  // 2️⃣ shrink window
                sum = sum - nums[i];
                i++;
            }

            if (sum == k) {   // 3️⃣ check
                len = max(len, j - i + 1);
            }

            j++;   // 4️⃣ move right pointer
        }

        return len;
    }
};
