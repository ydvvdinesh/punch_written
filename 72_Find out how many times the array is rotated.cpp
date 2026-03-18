//index of minimum element of sorted array = how many times a array is rotated 
class Solution {
public:
    int findKRotation(vector<int> &nums)  {
         int n = nums.size();
        int ans = INT_MAX;
        int low = 0;
        int high = n-1;
        int index = -1; // kyuki index zero se start hota hai
        while(low <= high){
            int mid = (low + high)/2;
            //if left part is sorted hume thodi pta hai konsa part sorted isliye hum dono ke liye condition rakhenge 
            if (nums[low]<=nums[mid]){
                // ans = min(ans,nums[low]); instead fucntion use it directly
                if (nums[low] < ans) {
                    ans = nums[low];
                    index = low;
                }
                //because sorted array ka first element hi hmesha chota hota hai 
                low = mid+1;//eliminates the left part
            }
            else{ // iski range mid to high rhegi
                //ans=min(ans,nums[mid]);
                 if (nums[mid] < ans) {
                    ans = nums[mid];
                    index = mid;
                 }
                high = mid-1;
            }
        }
        return index;
    }
};
