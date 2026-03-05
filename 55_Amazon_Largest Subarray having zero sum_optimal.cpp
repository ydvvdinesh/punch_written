class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int sum = 0;
        int maxi = 0; //for the count
        for(int i = 0;i<n;i++){
            sum = sum + nums[i];
            if (sum ==0){
                maxi = i+1; // count the index 
            }
            else if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi,i-mpp[sum]); // yadi hashmap me h toh current prefix sum ke index me se first occurence waala sum hta denege 
            }
            else{
                // nahi h toh hash map me last element tak key = prefix sum and value index ko store krte jayenge 
            mpp[sum] = i; 
            }
        }
        return maxi;
    }
};
