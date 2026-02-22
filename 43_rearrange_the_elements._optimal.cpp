//optimal approach
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n); // temp ke saath size assign krna pdega
       int posindex = 0;
       int negindex = 1;
        for (int i = 0; i<n;i++){
            if (nums[i]>0){
                temp[posindex]=nums[i]; // temp [i]=nums[i] - that`s why we don`t use So if nums[3] is positive, it goes to temp[3] — not necessarily an even index.
                posindex = posindex + 2;
            }
            else if (nums[i]<0){
                temp[negindex]=nums[i];
                negindex = negindex + 2;
            }
        }
        return temp;
    }
};
