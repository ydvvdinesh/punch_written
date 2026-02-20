//better approach - piche me sum har element ka kar rahe the isme hum next elemnt ko pichle waale ke sum me add krdenege by observation
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n = nums.size();
       int maxi = INT_MIN;
       for (int i =0 ; i<n; i++){ // ye loop array iterate krwayega
            int sum = 0;
        for (int j =i; j<n; j++){ // ye loop har element ke saare case legi 
                sum = sum + nums[j];// 
                maxi= max(sum,maxi);
        }
       } 
       return maxi;
    }
};
//o(n2) - time complexity is very large
