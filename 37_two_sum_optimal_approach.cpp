//optimal approach for variety 2 jisme index nikalna hai
// logic - pure me iterate krna hai and requried elemnts jo chayiye target pura krne me usse khelna hai usko , hum ek map data structured lenge jo , required element ko check krenge ki wo map me hai ki nahi , yadi nahi toh hum usse hum me store krwaenenge for future checking yadi hai yes ya value dedenge 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
      map <int, int> mp;
      for (int i = 0; i<n; i++){
        int a = nums[i]; // number jiske saath dekhna ki iske saath more needed kitne hai
        int required = target - a;
        if(mp.find(required)!= mp.end()){ // yadi milegya waale condition hai or Agar jo number mujhe chahiye (pair banane ke liye) wo pehle se map me hai
            return {mp[required], i};
        }
        mp[nums[i]]=i;
      }
      return {-1};
    }
};
