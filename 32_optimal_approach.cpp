//logic = 2 pointers concept sr krenge 
// step -1 comparsion kro and chote ko lena hai dono me se and same h toh ek koi bhi lelo but ye check karke ki phele ye kisne liya toh nahi
// step - 2 bus ye dhyan rakhna hai piche jo lechuke hai woh future/ present me nahi lena hai iske liye humne back ka use kiya and size kabhi zero nahi hoga kyuki back compare piche waale se hi lrega 
// step - 3ou of bond chla jaye toh uska jugad h alag alag iterate krwa do
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int i = 0 ; // kyuki dono ieration 0 se hogi nah
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        while (i < n1 && j < n2){ // i iterate krega n1 tak mtlb khud ke aarray ke size tak and j2 khud ke size n2 tak
            if (nums1[i] <= nums2[j]){
                if (ans.size() == 0 || ans.back() != nums1[i]){  
                    /*Agar ans empty hai (size == 0) toh bina compare kiye direct nums1[i] ko push kar do
Warna (ans empty nahi hai)
 ab safely ans.back() se compare karo
agar last element ≠ current element → push karo in one */
                    ans.push_back(nums1[i]);
                }
                i++;
            }
            else {
                if (ans.size() == 0 || ans.back() != nums2[j]){
                    ans.push_back(nums2[j]);
                }
                j++;
            }
        }

        // ye dono while isliye use kiye gaye hai ki yadi ieterate karte karte ek out of bond chla jaye toh dusra khud pura krle 
        while (i < n1){ // yadi dusra na chale toh ye apna kaam kr jaye 
            if (ans.size() == 0 || ans.back() != nums1[i]){
                ans.push_back(nums1[i]);
            }
            i++;
        }

        while (j < n2){ // yadi dusra na chale toh ye apna kaam kr jaye 
            if (ans.size() == 0 || ans.back() != nums2[j]){ //size waala part aage aayega tabhi toh check hoga na
                ans.push_back(nums2[j]);
            }
            j++;
        }

        return ans;
    }
};
