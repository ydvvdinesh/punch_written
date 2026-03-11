//optimal by obervation , aage se prefix count and and piche se jo maximum ho woh return krdo yadi coiunting time zero aajaye toh usko one bna do , and saath me count rakho 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n = nums.size();
       // ek loop me hi kaam krna h toh woh reasoning formula lga lo n-i-1
       int maxi = INT_MIN;
       int prefix_sum = 1;
       int suffix_sum =1;
       for (int i = 0; i<n; i++){
        if (prefix_sum == 0){ //These are two separate if statements, not else if. jab do ho alag alag toh dono chalti hai
            prefix_sum =1;
        }
        if(suffix_sum ==0){
            suffix_sum = 1;
        }
            prefix_sum = prefix_sum * nums[i];
            suffix_sum = suffix_sum * nums[n-i-1];
            maxi = max(maxi,max(prefix_sum,suffix_sum));
        
       } 
       return maxi;
    }
};
