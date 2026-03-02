//better approach = using map
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        vector<int> ls;
        int min = (int)n/3 + 1;
        for (int i = 0; i<n; i++){
            mpp[nums[i]]++; // key = nums[i] , ye aati hai toh count ki value by 1 increase hogi
            //mpp[key]= value
            if(mpp[nums[i]]==min){ //yadi nums key ki value mini mal ke barbar hai toh 
                ls.push_back(nums[i]);
            }
            if (ls.size()==2) break;
        }
        return ls;
    }
};
