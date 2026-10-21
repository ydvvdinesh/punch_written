//better approach 
//1. sort it 
//har baar teen ka jump karna hai yadi jispe  ho and last waala current ke equal nahi jai toh that means woh hi single hai otherwise baaki toh teen teen hi hai 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 1; i<n; i = i+3){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }
        //yadi last element huwa
        return nums[n-1];
    }
};
