//brute aproach - linear search 
//optimal approach - using binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while (low <= high){
        int mid = low + (high - low)/2;
            if (nums[mid] == target)
                return mid;
            /*if left part is sorted then we are going to use this condition for checking 
            arr[low] <= arr[mid]
            */
            //if left part is sorted
            if(nums[low]<=nums[mid]){
                //after getting the sorted array , we have to check that the target we have to find is present or not in the sorted array 
                if(nums[low] <= target && target <= nums[mid]){
                    //it means we get our target in that sorted array which is sorted. so now we would negelect the right part
                    high =mid -1;
                }
                else{
                    //target is not present in our selected part that means target is right part then we negelct the left part and we want to right part
                    low = mid +1;
                }
            }
/*Question ??? if hum aise hi dono ja skte hau then why we go with part ANswer - because we are checking ki konsa sorted hai , kyuki usme hi binary search valid h na bete ,
yadi hum left me nahi mila then we move to another part that is defintly sorted which is given in question*/
                
                //if right is sorted
                else{
                    if(nums[mid] <= target && target <= nums[high]){
                         low =mid +1;
                    }
                    else{
                        high = mid-1;
                    }
                }
            }
        return -1;
    }
};

/*
Important Interview Insight

Your question:

“Why not go both sides?”

👉 Because:

Binary search works only on sorted data

In rotated array, only one half is guaranteed sorted

So we identify sorted half → apply binary search logic
*/
