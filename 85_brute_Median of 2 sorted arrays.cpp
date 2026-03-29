// brute - using 2 pointer and khud kiya hai
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0 , j =0;
        vector <int> arr; //isme saare sorted elements rakhenge
        //merge the sorted array
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1){
            arr.push_back(nums1[i]);
                i++;
        }
        while(j<n2){
             arr.push_back(nums2[j]);
                j++;
        }
        int n = n1 + n2;
        //yadi odd a toh direct mil jayega
        if(n%2 == 1) return arr[n/2];
        /*🔥 Why 2.0?
Forces floating point division
Otherwise 2 → integer division (wrong answer)*/
      return (arr[n/2] + arr[(n/2)-1]) / 2.0;
    }
};
