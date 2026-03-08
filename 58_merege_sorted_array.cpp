//brute force approach 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = 0;
        int right = 0;
        vector <int> ans;
        while (left<m && right <n){
            if (nums1[left]<=nums2[right]){
                ans.push_back(nums1[left]);
                left++;
            }
            else{
                ans.push_back(nums2[right]);
                right++;
            }
        }
        while (left<m){
            ans.push_back(nums1[left]);
                left++;
        }
        while (right < n){
            ans.push_back(nums2[right]);
                right++;
        }
        //in void function we change return a array / vector
        // problem states in last line - The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
        //we are using this for loop for adding all elments in 1 array as questions states
        for (int i =0; i<m+n; i++){
            nums1[i] = ans[i];
        }
        
    }
};
