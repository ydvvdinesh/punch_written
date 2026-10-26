//with sorting , in next approach we will solve this without sorting 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        //phele k elements ko daal denge mai and hisab bnaye rakhne ke liye 
        for(int i = 0; i<k; i++){
            pq.push(nums[i]);
        }
        //now ek window bna di 
        for(int i = k; i<n; i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
