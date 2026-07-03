//question - we have given a array and we have to tell that are we able to went at last of the array 
// element of array is representing how far can it go , example if index 1 has 2 value then it went to upto index 3, maximum btayenge
//so our task is to return true and false , edge case sabse phele zero dekhna hai yadi zero nahi hai , that means hum easily last tak poch jayenge because yadi zero nahi hai toh last value of any index 1 rhegi toh 1-1 jump krte hum poch jayenge
//approach / key idea - we use maxindex variable ,that tell us hum kitna max ja skta hai har particular index pe and jab hum traverse kar rahe hai index yadi maxindex se bda chla gaya toh false ho jayega because max index hum ye btayega kitna max ja skte hai , usse aage nahi ja skate and yadi hum bde index pe poche , toh poch kaise , jab rasta aage band ho raha , ek maximum limit dega yadi uske bahar gye mtlb galat hai kyuki waah poch hi nahi skate
//optimal approach - zerobased indexing
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxindex = 0; // this tells us till that index kitne door ja skte hai and yadi hum usse jada door gaye toh gaye kaise beech me rasta toh hai hi nahi
        for(int i = 0; i<n; i++){
            if(i > maxindex) return false;
            maxindex = max(maxindex, i+nums[i]);
        }
        return true;
    }
};
