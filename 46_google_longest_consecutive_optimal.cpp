//optimal approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0){
            return 0;
        }
        int longest = 1;
        int count = 0 ;
        unordered_set<int> st;
        for(int i =0;i<n;i++){
            st.insert(nums[i]);
        }
        // the main logic part - yadi x-1 exist nahi krta tabhi hum x+1 ke raste pe badhenege
        for(auto it : st){ // ye set me iterate karne ke liye
        //“Search in the set st for the value (it - 1) == element not found or agar current number ka previous number (it-1) set me nahi hai,toh ye number sequence ka starting point hai”
            if (st.find(it - 1) == st.end()){ // agar it-1 exist nahi karta, matlab ye sequence ka starting element hai it kya h isme , it is element form set at one time
                count = 1;
                int x = it;
                while (st.find(x+1) != st.end()){ // // jab tak x+1 set me milta rahe, sequence aage badhate raho
                    count = count +1;
                    x=x+1;
                }
            }
            longest = max(longest,count);
        }
        return longest;
    }
};
