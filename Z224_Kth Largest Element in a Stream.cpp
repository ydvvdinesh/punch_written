class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // ye sorting ka hisab kitab dekh leti hai 
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            //jab tak bhaari ja rahi hai tab tak bro 
            if(pq.size()<K){
                pq.push(nums[i]);
            }
            //ek bar size full to bas phir top waala check hoga 
            //phela mai size dekha jayenge ki heap ka utna hai ki nahi dusri condition me value comare hogi 
            else if(pq.top()<nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < K){
                pq.push(val);
                return pq.top();
            }
        if(pq.top()<val){
                pq.pop();
                pq.push(val);
            }
            return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
