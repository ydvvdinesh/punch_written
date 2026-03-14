//iterative code
// assuming seacrh space is not int_max 
//low = starting pointer 
//high = last pointer
//mid = (low+high)/2 for not int_max case
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        /*
        3 condtions hoti hai - yadi mid nikala mil gaya that 
        2) yadi target bda hai toh righ tme jaana pdega kyuki sorted array hai na dlow ko mid ke aage bhejna pdega
        3) chota h toh left me iterate krenge ,  toh waale pointer ko mid se peeche laana pdega kyu search space sahi bna rhena chayiye
        */
        while(low<=high){
        int mid = (low +high)/2; // mid har baar calculate hoga, kyuki yadi first pe nahi milta hai toh low search space bdelega 
            if (nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){ // search in right part
                low = mid +1;
            }
            else {
                high = mid -1; //search in left part
            }
        }
        return -1;
    }
};
