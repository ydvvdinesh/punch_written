//brute force approach - har window me jaoo and find the maximum and us index me wo maximum dedo in answer list 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> list;
        //why n-k , because uske baad window nahi bnegi dry run ke baad dekha 
        for(int i =0; i<=n-k; i++){
            int maxi = nums[i]; // we assume first hi start hai and har window ke liye reset hoga 
            // why i-k+1 is the last index of the current window
            for(int j =i; j<= i+k-1;j++){
                maxi = max(maxi, nums[j]);
            }
            list.push_back(maxi);
        }
        return list;
    }
};
