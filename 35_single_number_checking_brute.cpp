//bruteforce approach
// logic - har bar ek element pakdo aaray ka and uski linear search krwado and jiska count one aaya linear seach me wo single hai mtlb wohi answer hai, har baar mtlb loop
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i<n; i++){
            int num = nums[i];
            int count = 0;
            for (int j = 0; j<n;j++){
                if (nums[j]==num){
                    count = count +1 ;
                }
            }
           if (count == 1){
            return num; // wohi num dega na jisko pakda ke har jagah check krwa rhe hai
           } 
        }
        return -1;
    }
};
