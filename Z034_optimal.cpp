//optimal approach - we are suing dequeue , hum isko ek traverse me complete krenge , in traversing hum window ki length ko same rakhenge , ek traf se add krenge dusri traf se remove and iske liye dequeue is the best data structure , and in dequeue hum index daalenge and one thing hum dhyan rakhna ki window ki size krab na ho and so uske liye we use i-k thing yadi front waale ka index iss value se kam ya same hai that means hum ek member add kr skate hai but before adding hume ek element delete karna pdega 
//and 2nd thing - dequeue me hum decreasing order se store krenge element ko jaise hi greater element aaya topmost se tha means order toota and hum woh greater hi chayiye toh hum baaki sabko remove kr  and in last wo akela bchega so we return dq.front
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> list;
        for(int i = 0; i<n; i++){
            //we have to maintain window 
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            //we have to maintain order of dequeue yadi bda aaya toh woh rhega baaki sab nikal jayega and last me wohi front hoga toh usko list me add kr denge
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back(); //sab back se nikalte jayenge
            } 
            dq.push_back(i);
            if(i>= k-1){
                list.push_back(nums[dq.front()]);
            }
        }
        return list;
    }
};
/*
// Optimal Approach (Monotonic Deque)
//
// We store indices in the deque.
//
// 1. Window maintain karni hai.
//    Agar deque ka front index current window ke bahar chala gaya hai
//    (dq.front() <= i-k), toh use remove kar do.
//
// 2. Deque ko decreasing order of values me maintain karna hai.
//    Agar current element nums[i] deque ke back waale element se
//    bada ya equal hai, toh back waale element future me kabhi
//    maximum nahi ban sakte, isliye unhe remove kar do.
//
// 3. Current index ko deque ke back me insert karo.
//
// 4. Jab first complete window mil jaaye (i >= k-1),
//    toh deque ke front par current window ka maximum element
//    hoga. Use answer me add kar do.
*/
