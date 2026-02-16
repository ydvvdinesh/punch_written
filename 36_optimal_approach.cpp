//optimal approach addition termantion if k greater simple

class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int i =0;// terminate krke aage badyega
        int j =0; // iterate krega pure array me 
        int n = nums.size();
        int sum = 0;
        int len = 0;
        while (j<n){
            if (j<n){
                sum = sum + nums[j]; // addition part
                j++;
            }
            while (i<=j && sum>k){ // termination part 
                sum = sum - nums[i];
                i++;
            }
            if (sum == k){
                len = max(len,j-i+1);
            }

        }
        return len;
    }
};
