//better approach - using stl
//brute is we have to explain in the interview and we will cover in the recursion
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
