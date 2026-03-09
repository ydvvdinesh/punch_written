//optimal approach - 2 pointer approach , left ko first ke last pe rakho and right ko second ke first pe and compare both yadi left waale ki value badi hai toh swap krte raho jab tak chota waala chota na mile , kyuki yadi wo mil gaya toh iska baaki toh usse chote hi , order ko hum baad me sort kr lenege
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = 0;
        while(left>=0 && right <n){
            if (nums1[left]>nums2[right]){
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else {
                break;
            }
            //jab array dono set hogaye toh unko order me leke aana hai
        }
            sort(nums1.begin(),nums1.begin()+ m); //You should sort only the first m elements of nums1, not the zeros
            sort(nums2.begin(),nums2.end());
            // problem says ki hume sab kuch nums1 mw chayiye toh daalo
            // m + i is used to place elements of nums2 into the empty part of nums1 starting from index m
           for (int i = 0; i < n; i++) {
             nums1[m + i] = nums2[i];
}
        }
};
