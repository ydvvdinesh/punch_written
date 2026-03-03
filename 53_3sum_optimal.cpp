//optimal solution - 2 pointer approach - sirf ye hi working apporach baaki sab time limit error de rahi hai
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans; //ek list declare karni pdegi jisme saare triplet store ho
        sort(nums.begin(),nums.end());
        for (int i = 0; i<n; i++ ){
            if(i > 0 && nums[i] == nums[i-1]) continue; //yahi samehai toh skip karna and edge case dhyan rakhne hai
            int j =i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else {
                    vector <int> temp = {nums[i],nums[j],nums[k]}; //just getting a list
                    ans.push_back(temp); 
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++; //yaha check kar rahe hai toh assignment nahi aayega bhai
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }

        }
        return ans;
    }
};
