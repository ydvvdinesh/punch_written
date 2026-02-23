class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      int maxi =INT_MIN;
      int n = nums.size();
      vector<int>ans;
      for(int i = n-1 ; i>=0; i--){
        if (nums[i]>maxi){
            ans.push_back(nums[i]); // tu leader hai 
        }
        maxi = max(nums[i],maxi);
      }
        reverse(ans.begin(), ans.end());
      return ans;
    }
};
