//optimal approach 
class Solution{
public:
    int subarraysWithXorK(vector<int> &nums, int k) {
        int n = nums.size();
        int xor_all = 0;
        int count =0;
        unordered_map<int,int> mpp;
        mpp[0] =1;
        for (int i = 0; i<n; i++){
            xor_all = xor_all^nums[i];
            int frontone = xor_all^k;
            if(mpp.find(frontone) != mpp.end()){ // frontonemil gaya toh k automatically mil jayenga na 
                count = count + mpp[frontone]; // frontone key ki value jo jitni baar aaya hai
            }
            mpp[xor_all]++; // varaible ko daalo bro
        }
        return count;
    }
};
