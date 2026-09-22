class Solution {
public:	
    void f(int ind,vector<int>& list,vector<vector<int>>& ans,vector<int>& nums, int n){
      // yadi last element pe pauch gaye toh ruk jayenge in array
      //nums jo gven hai question mai
      if(ind == n){
        ans.push_back(list);
        return;
      }
      //take or not take 
      //take , waala hai toh , list me daalenge
      list.push_back(nums[ind]);
      f(ind +1, list,ans, nums,n);
      list.pop_back();
      //yadi dusre waala , jo liya nahi woh aise rhega , not take
      f(ind + 1, list, ans, nums, n);
    }
    vector<vector<int> > powerSet(vector<int>& nums) {
      int n = nums.size();
        vector<vector<int>> ans;
        vector<int> list;
        f(0,list,ans,nums,n);
        return ans;
    }
};
