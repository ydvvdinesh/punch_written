//another optimal - using gap thing , left waala chota hai toh sahi hai yadi bda hota toh swap kr deneg 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int len = m + n;
        int gap = (len/2) + (len%2);

        while(gap > 0){

            int left = 0;
            int right = left + gap;

            while(right < len){

                // nums1 and nums2
                if(left < m && right >= m){
                    if(nums1[left] > nums2[right - m]){
                        swap(nums1[left], nums2[right - m]);
                    }
                }

                // nums2 and nums2
                else if(left >= m){
                    if(nums2[left - m] > nums2[right - m]){
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }

                // nums1 and nums1
                else{
                    if(nums1[left] > nums1[right]){
                        swap(nums1[left], nums1[right]);
                    }
                }

                left++;
                right++;
            }

            if(gap == 1) break;
            gap = (gap/2) + (gap%2);
        }

        // copy nums2 into nums1
        for(int i = 0; i < n; i++){
            nums1[m + i] = nums2[i];
        }
    }
};
