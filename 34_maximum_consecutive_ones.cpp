//logic - ierate and 1 ginte jaoo and jaise zero aaye toh counting dobara se shuru krdo 
// saath me maximum count bhi rakho toh pta rhe ki ek baar me kitna maximum gaya uska count rakhe
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        int n = nums.size();
        for (int i = 0; i<n ; i++){
            if (nums[i]==1){
                count = count +1;
                maxi=max(maxi,count); //maxi increases because count increases, and then we assign , jitna count jayega maxi usse store krega
            }
            else{
                count = 0;
            }
        }
        return maxi;
    }
};
