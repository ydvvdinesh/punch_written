//only optimal approach chlegi on leetcode
//better approach using hashing and comparing two variable isme and sort return ke time krnege , jo hmari space complexity increase krega
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st; // storing the all triplets , toh list daalo na argument me  , preventing from the duplication
        for (int i = 0; i<n; i++){
            set<int> hashset; // set using to store the elemnets and compare with the value k
            for (int j =i+1; j<n;j++){
                int third = -(nums[i]+nums[j]);
// is condition means that we are looking for third , right waali not a value its a points ki nahi h ellement set me , if they are not equal that means we found the element
                if (hashset.find(third)!= hashset.end()){
                    vector<int> temp = {nums[i],nums[j],third}; // k nahi aayega third aayega
                    sort(temp.begin(),temp.end());
                    st.insert(temp);

                }
                hashset.insert(nums[j]); //ellemnet insert hoga naki ki index
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};
