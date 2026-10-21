class Solution {
public:
    int singleNumber(vector<int>& nums) {      
        int n = nums.size();  
       unordered_map<int,int> mpp;
       for(int i = 0; i<n; i++){
        mpp[nums[i]] = mpp[nums[i]] + 1;
       }
       for(auto it : mpp){
        if(it.second == 1){
            return it.first;
        }
       }
       return 0;
    }
};
