//pace optimaztion extra dp array use kare bina solve karna using some varibale 
//jo ike piche waale saare kaam prev krega and uske piche ke prev2
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];   
        int prev2 = 0;
        for(int i = 1; i<n; i++){
           int pick = nums[i];
            if(i>1){
                pick = nums[i] + prev2;
            }
            int nonpick = 0 + prev;
            int curr = max(pick, nonpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
