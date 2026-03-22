//same like koko eats bnana 
//brute 
/*
1. total sum = ceil of indiviual numberof array divides by divisor + due it for all // cumulative sum
2. jis divisor pe sum <= threshold that is the answer
*/
// we are creating a function that is going to find out the total sum after the divivson with individual which we are gonna compare with threshold
int totalsum(vector<int>& nums, int divisor){
    int sum = 0;
    // ceil(nums[i]/divisor) = (nums[i] + divisor - 1) / divisor
    for (int i =0; i<nums.size();i++){
        sum = sum + (nums[i] + divisor - 1) / divisor;
    }
    return sum;
}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
    //limit of divisor is 1 to maxi number in that array , kyuki uske baad toh sab zero
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0 ; i<n;i++){ // for finding the maximum
        maxi = max(maxi,nums[i]);
    }
    for (int i = 1 ; i<= maxi; i++){ // the loop for the divisor ,
        int munni = totalsum(nums,i); // jaise divior bdelega vaise hume answer milega total sum ka 
        if(munni<=threshold){
           return i;// i will be not the index its the divisor 
        }
    }
     return -1;// nahi mila toh ye return ho jayega
    }
};
