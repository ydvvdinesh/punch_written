// target is number can be inserted without breaking the sorted order.
//Lower bound is used to find the position where a value should be placed in a sorted array so that the array remains sorted.
//Upper bound is used to find the position where a value should be placed in a sorted array such that all elements before that position are less than or equal to the value, and the array remains sorted.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lowerbound = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return lowerbound;
    }
};
