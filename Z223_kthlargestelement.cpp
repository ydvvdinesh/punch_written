class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        //sort  the array in the descending , we have two way we can use the greater<int>() or we can go with the compartor
        sort(nums.begin(), nums.end(),greater<int>());
        int ans = 0;
        //we go with 0 based based indexing
        //kth largest , it means k yadi 2 hai toh it means 2 largest  
        for(int i = 0; i<k;i++){
            ans = nums[i];
        }
        return ans;//last mai answer ye hi store krta milega 
    }
};
