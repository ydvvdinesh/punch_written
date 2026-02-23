//optimal - back side se jayenge
/*
Step-1 find the breaking index -  piche waale aage waale se chota hona chayiye
Step-2 swap the smallest element in right side(but greater then index) with index
Step -  3 sort the remainig elements
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
       for (int i = n-2; i>=0; i--){ // kyuki last waala element same rakhna hai isliye n-2 
        if (nums[i]<nums[i+1]){
            index = i;
            break;
        }
       }
       if (index==-1){
        reverse(nums.begin(),nums.end());
        return;
       }
       for(int i = n-1; i>=index;i--){
        if (nums[i]>nums[index]){
            swap(nums[i],nums[index]);
            break;
        }
       }
       reverse(nums.begin() + index + 1, nums.end());
    }
}; 
