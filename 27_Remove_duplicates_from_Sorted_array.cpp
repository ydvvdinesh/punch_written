// 2 pointer se jayenge e array ko iterate krega and dusra elements ki poision jo hum phele se compare kr rhe hai usko and woh elemenst jo future elemts ko find krengge 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // index- elments ke kaam krne ke liye
        for (int j =1; j <nums.size();j++){ // j - iterate krwane kie liye 
            if (nums[j]!=nums[i]){
                nums[i+1]= nums[j];
                i++;
            }
        }
        return i+1; // i+1 is sixe of modfied array // uniquwe ko aage laana hai and baaki bhul jaoo
    }
};
