//optimal - same like 3sum and but one difference we have to fix two elementy and ha isme set use nahi hota
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for (int i = 0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for (int j = i+1;j<n;j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue; // piche waala j repeat na ho 
                int k =j+1;
                int l = n-1;
                while(k<l){
                    long long sum = 1LL*nums[i] + nums[j] + nums[k] + nums[l];
                    /*1LL is a long long literal
1LL * nums[i] converts nums[i] into long long
Then whole expression becomes long long math*/
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else if(sum==target){
                        vector <int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};
