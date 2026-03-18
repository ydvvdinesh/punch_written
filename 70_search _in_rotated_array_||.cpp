//ek condition ki yadi element equal hai toh sorted part kaise identfy krenge for thatsolution is  we shrink it until we can`t get the our sorted part -- optimal approach - o(n/2) 
class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low =0; 
    int high =  n-1;
    while (low <= high){
        int mid = low + (high-low)/2;
        //in bineary search this statement this answer remember my boy , other toh bus search space manage karti hai
        if (nums[mid]==target){
            return true;
        }
        //if duplicates is ther 
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            //shrink it untill we can`t get our sorted part
            low = low +1;
            high = high -1;
            continue;
        }
        //if we get left part as sorted
        if(nums[low]<=nums[mid]){
            //target is there  
            if(nums[low]<= target && target<=nums[mid]){
                //we will put complete power of search space in left area
                high = mid-1;
            }
            //not present here, then meanswe have to move our search space to right part which is already sorted
            else{
                low = mid+1;
            }
        }
        else if(nums[mid]<=nums[high]){
                        //target is there  
            if(nums[mid]<= target && target<=nums[high]){
                //we will put complete power of search space in right area
                low = mid+1;
            }
             else{
                high = mid-1;
            }
        }
    }
    return false;
    }
};
