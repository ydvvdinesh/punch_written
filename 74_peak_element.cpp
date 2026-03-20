//brute approach we have to think about the same like single element , just one condition - peak elemenet aage and piche ke element se value badi honi chayiye jispe hum khade hai
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 0; // if array has single element
        //we have the -infinte to array to - infinite
        if (nums[0]>nums[1]) return 0;
        if (nums[n-2]<nums[n-1]) return n-1;
        // we check for all the element which is remaining in the array
        for (int i = 1; i<n-1;i++){
            if (nums[i]>nums[i-1] && nums[i]> nums[i+1]){
                return i;
            }
        }
        return -1; // nahi mila toh and statement say koi bhi ek chlega
    }
};
