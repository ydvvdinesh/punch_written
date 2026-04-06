//better solution - two pointer & sliding windows
//question statement - longest subarray with k flipping zeros (we can flip this zero to 1)
//converted - longest subarray with at most k zeros
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0, r=0;
        int maxlen =0;
            int zeros =0;
        while(r<n){
            if(nums[r] == 0) zeros++;
            /*
            We shrink from the left to make it valid again
            Core Logic
            At any moment, we want:
             valid window → zeros ≤ k
            If not:
            we FIX it by removing elements from left
            */
            //zeros is greater than zero then we have to trim down from the left, so what we do we move left pointer(l) to right side and when we get when we get zero in the array then we subtract -1 from zeros count that intreprete 
            //“If zeros exceed k, move left pointer to shrink the window, and whenever a 0 goes out of the window, decrease the zero count.
            while(zeros>k){
                if (nums[l] == 0){
                    zeros--; // ham zeros isliye nikalrhe toh make our condition valid and then we check through all
                    l++; // jab tak zeros aukat me nahi aate tab tak kaam chalta rhega 
                }
            }
            if(zeros<=k){
                int len = r-l+1;
                maxlen= max(maxlen,len);
            }
            r++;
        }
        return maxlen;
    }
};
