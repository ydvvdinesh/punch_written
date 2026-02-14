//optimal approach
//1. we go with 2 pointer approach , ek iterate krwayega and dusra swapping handle krega , ek index humsa zero pe rhega
//step -1 find the zero and put j to it 
//step-2 now iterate the loop in right side of zero and find non zero number and swipe
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = -1; //if ye -1 hi raha toh koi zero hi nahi hai array me
        for (int i = 0 ; i<n ; i++){
            if (nums[i]==0){
                j=i;
            }
            break;
        }
        for (int i = j+1 ; i< n; i++){
            if (nums[i]!=0){
                swap(nums[i],nums[j]);
                j++; // kyuki zero hui toh ye usko follow krega 
            }
        }
    }
};
