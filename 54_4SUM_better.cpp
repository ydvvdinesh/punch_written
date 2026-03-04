//better - using set checking do element ke bich waale lene hai , bast set ke eement se check krwange baki same hai like brute
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set <vector<int>> st; // set to store the answer 
        for (int i = 0; i<n; i++){
            for (int j = i+1;j<n;j++){
                set<long long> hashset; // checking ki fourth dono jagah same hai toh unique me quad bn jayega
                for (int k =j+1;k<n;k++){
                    long long sum = 1LL *nums[i] + nums[j] + nums[k];
                    long long fourth = target - sum;
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int>temp = {nums[i] , nums[j] , nums[k] ,int(fourth)};
                        sort(temp.begin(),temp.end());
                            st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
         return ans; 
    }
};
