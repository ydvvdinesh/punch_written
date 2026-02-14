//brute force approach
// Moving all zeros to the last of the array
//logic - 1. non zero ko ek array me store kro 
//2. then unko array ke aage shift kardo
//3. bche huye elements ko zero assign krdo 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector <int> temp;
        for (int i = 0 ; i<n; i++){
            if (nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        for (int i = 0 ; i<temp.size();i++){ // number of non zeros  = temp array size
            nums[i]=temp[i];
        }
        for (int i= temp.size();i<n;i++){
            nums[i]=0;
        }
    }
};
