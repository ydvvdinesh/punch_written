//optimal approach - leader - right me jo maxi hai woh uss number se chota rhena chayiye YADI HAI toh ledeadr hoga
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      int n = nums.size();
      vector <int> ans;
      int maxi = INT_MIN;
      for (int i = n-1;i>=0;i--){ // abhi sorted array dega if you want same order toh reverse krdo
        if (nums[i]>maxi){
            ans.push_back(nums[i]);
        }
        maxi = max(nums[i],maxi);
      }
      reverse(nums.begin(),nums.end());
      return ans; 
    }
};
