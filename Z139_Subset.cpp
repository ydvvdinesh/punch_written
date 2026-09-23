//har subset ka sum dena hai , power set use karke saare subset yaha sequence genefrate kro and unka sum dedo simple
//fark itna hai ki list mai daalne ki jagah sum mai sab jod dene hai 
class Solution {
  public:

  void f(int ind, vector<int>& nums, int sum,  vector<int>& ans, int n){
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        //now if we take 
        f(ind+1, nums, sum + nums[ind], ans, n);
        // if we don`t take, why we add sum bhai 
        f(ind+1, nums, sum, ans, n);
    }

    vector<int> subsetSums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        f(0,nums,0,ans,n); //starting mai sum bhi zero hai and we have to process 0 which is next index 
        return ans;
    }
};
