//optimal approach 
// logic - 2 pointer approach ,array ko  sort krke ek index ko zeroth index pe bithyenge and another array ko last index pe   , yadi do index ki value ka sum jaada hoga target se toh sum ko decrease krnge toh last waala piche move krega "decrement " and jab sum ki value kam hogi toh toh value increase krni pdegi toh left waale to right ki trf move krwayenge and in sort array left to right value badhti hai 
class Solution {
public:
    read twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = n-1;
        while (left < right){
            int sum = nums[left] + nums[right];
            if (sum == target){
                return "Yes";
            }
            else if(sum<=target){
                left++;
            }
            else{
                right--;
            }
        }
