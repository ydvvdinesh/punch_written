//using lb and up
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        auto first = lower_bound(nums.begin(),nums.end(),target);
        auto last = upper_bound(nums.begin(),nums.end(),target);
        int firstind = first - nums.begin();
        int lastind = (last - nums.begin()) - 1;
        //this condition if elememt in not present becaus elb gave us the answer , we have to put some restrication over here
        if (first == nums.end() || *first != target){ // first = lb 
            return {-1,-1};
        }
        else{
            return{firstind,lastind};
        }
    }
};
