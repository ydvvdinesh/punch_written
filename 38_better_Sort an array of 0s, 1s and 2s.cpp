//beter approach 
// logic - count the all numbers 0 and 1 and 2 , after counting rewrite the numbers in orginal array
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0 , count1 = 0 , count2 = 0;
        for (int i = 0; i <n ; i++){ // iterate thrugh a array count the 0 and 1 and 2
            if (nums[i]==0){
                count0 = count0+1;
            }
            else if (nums[i]==1){
                count1 = count1+1;
            } 
            else if (nums[i]==2){
                count2 = count2+1;
            }
        }
        // ye hume pta hai ki sort hai toh phele saare zero aayenge then saare 1 then saare 2 toh hum manually daal denge 0 to that position then next to next similarly
        for (int i = 0; i<count0;i++){
            nums[i]=0;
        }
        for (int i = count0; i<count0+count1;i++){
            nums[i]=1;
        }
        for (int i = count0+count1; i<count0+count1+count2;i++){
            nums[i]=2;
        }
    }
};
