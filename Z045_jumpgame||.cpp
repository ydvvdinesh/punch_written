//brute force - by recirsion saari possiblity nikalo but hum optimal one se jayenge 
//optimal approach - we have to find the minimum jumps through with we can reach the last destination
//keyidea - we use the range based approach - ek index me gaya then check kiya ki usse index se farthest kha tak ja sakte hai , toh ek range bn gayi ki jha tak ja skte hai waah tak , ab uss range me ek element pick karna jiske thorugh hum maximum travel kar skte , bas aise hi haar baar karna hai we get our result and saath saath jump count karte rhenge
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0; //at the index jiski range dekh rahe hai
        int r = 0; //maximum , last point of the 
        int farthest = 0; //ye range ko woh element hai jo hume farthest leke jayega
        int jumps = 0;
        while(r<n-1){
            //ye loop toh maximum nikalne ke liye hi hai and maximum range me nikalna hai so range l to r hogi 
            for(int i =l; i<=r; i++){
                farthest = max(farthest, i+nums[i]); // 0 based indexing
            }
            jumps++; //   // One jump is used to reach the next range
            l = r+1;
            r = farthest;
        }
        return jumps;
    }
};
//t.c = o(n) because while sirf check kar rahi hai
