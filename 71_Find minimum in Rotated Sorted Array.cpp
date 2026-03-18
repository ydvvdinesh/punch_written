//optimal approach - binary search 
/*
1.selects the which part is sorted 
2.after getting the sorted part, pick minimum element in that part and eliminate to that part or move to another part
3.update the ans for last part also
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            //if left part is sorted hume thodi pta hai konsa part sorted isliye hum dono ke liye condition rakhenge 
            if (nums[low]<=nums[mid]){
                ans = min(ans,nums[low]); 
                //because sorted array ka first element hi hmesha chota hota hai 
                low = mid+1;//eliminates the left part
            }
            else{ // iski range mid to high rhegi
                ans=min(ans,nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};
//time complexity - o(logn)
