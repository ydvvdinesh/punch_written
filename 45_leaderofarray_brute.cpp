//brute - har element check kro
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
    int n = nums.size();
      vector <int> ans;
      for (int i = 0; i<n; i++){
        bool leader = true;
        for (int j = i+1; j<n;j++){
            if(nums[j]>nums[i]){
                 leader = false;
                break;
            }
        }
        if (leader == true){
        ans.push_back(nums[i]);
        }
      }
      return ans;
    }
};
