//brute force approach
// pick one element har baar and check kro sabse 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0 ; i<n; i++){ //ek element pick karne ke liye har baar
            int count = 0;
            for (int j =0; j<n; j++){ // har baar check krne ke liye
                if (nums[j]==nums[i]){
                    count ++;
                }
            }
            if(count > n/2){
                return nums[i]; // return the selected element
            }
        }
        return -1;
        }
};
//n^2 time complexity isliye time limit excedded 
