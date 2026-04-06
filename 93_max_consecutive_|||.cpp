//brute - by generating all subarray
//question statement - longest subarray with k flipping zeros (we can flip this zero to 1)
//converted - longest subarray with at most k zeros
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0; // length of biggest subarray which have atmost k subarray
        for (int i =0 ; i<n; i++){
        int zeros = 0; // har sub array ke liye count krne hai 
        for (int j = i; j<n; j++){
            if (nums[j] == 0){
                zeros += 1;
            }
            if (zeros <= k){
               int len = j-i+1; // way to find the length between the array, when we have pointer
                maxlen = max(len,maxlen);
            }
            else{
                break;
            }
    }
        }
        return maxlen;
    }
};
