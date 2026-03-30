//optimal we go with count method , directly finding the number , not merging directly the number
//yaha humne phele hi bta diye ki yadi ye mile toh done hai seen 
// thoda sa hypo waala , part humne phele hi total element count kr liye hai, raat lena 
///RAAAAAT LENAAAAAAAAAAAAAAAAAAAAAA
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;
        int ind2 = n/2; // ye dono index nikal liye jo possible ho skte hai 
        int ind1 = ind2 -1;
        int el1 = -1, el2 = -1;
        int i = 0, j =0;
        int cnt =0; // hypothecial thing , its a index part
        while(i<n1 && j<n2){
            if (nums1[i]<nums2[j]){
                if (cnt == ind1) el1 = nums1[i]; // yadi cnt ka index and total elements ka index same hai toh pakka el1 wohi value
                if (cnt == ind2) el2 = nums1[i];
                cnt++;
                i++;
            }
            else{
                if (cnt == ind1) el1 = nums2[j]; 
                if (cnt == ind2) el2 = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i<n1){
            if (cnt == ind1) el1 = nums1[i];
                if (cnt == ind2) el2 = nums1[i];
                cnt++;
                i++;
        }
        while(j<n2){
            if (cnt == ind1) el1 = nums2[j]; 
                if (cnt == ind2) el2 = nums2[j];
                cnt++;
                j++;
        }
        if (n%2 ==1) return el2;
        return (el1+el2)/2.0; // 2.0 khud casting kr dega
    }
};
//isme ek count hypothecial index count krega jisse answer lenge 
/*
even hai toh 2 index lgenge value ke liye 
and odd ek toh ek
toh 2 index ki 2 value hogi that we will by pointer yadi count equal h index ke toh uss index ki value hi answer waali hogi ,
*/
