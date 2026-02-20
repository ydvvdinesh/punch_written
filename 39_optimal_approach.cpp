//optimal approach - we use Moore's Voting Algorithm for finding the element then we start the another loop for checking that moore voting is correct or no
/*
1.Find a candidate (not guaranteed majority)
2.Verify the candidate (confirmation loop)
*/
//optimal approach - we use Moore's Voting Algorithm for finding the element then we start the another loop for checking that moore voting is correct or no
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count= 0;
       int el;
       int n = nums.size();
       //Phase 1: Find a candidate (not guaranteed majority)
       for (int i =0;i<n;i++){
        if (count == 0){
            count = 1;
            el = nums[i];
        }
        else if(nums[i]==el){
            count++;
        }
        else{
            count--;
        }
       }
    //2. Verify the candidate or element (confirmation loop)
    int count1=0;
    for (int i =0; i <n; i++){
        // ya jo element use kr rahe hai woh hum moore bhai de chhuka hoga 
        if (nums[i]==el) count1++;
        }
        if (count1>n/2){
// returning element not the count 
        return el;
        }
    return -1;
    }
};
