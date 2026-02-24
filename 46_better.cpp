//better approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        sort(nums.begin(),nums.end());
        int count = 0; // count the elements after jab sequence bn rahi ho
        int longest = 1; // sabse bda sequence 
        int lastsmaller = INT_MIN; // ye bahut important hai bhai
        for (int i = 0; i<n; i++){
        if(nums[i]-1 == lastsmaller){
            count = count +1;
            lastsmaller = nums[i];
        } 
        else if( lastsmaller != nums[i]){
            count = 1;
            lastsmaller = nums[i];
        }
        longest = max(count,longest);
        }
    return longest;
    }
};
