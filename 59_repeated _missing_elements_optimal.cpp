//optimal approach
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        /*complete logic
        array ke sum me total ka natural ka sum - karna hai 
        x = repeating 
        y = missing 
         s-sn = x-y
         s2-s2n = x^2 - y^2 
        */
        int n = nums.size();
        long long sn = (n*(n+1))/2;
        long long s2n = ((long long)n*(n+1)*(2*n+1))/6; // this we have to make to long long
        long long s=0;
        long long s2=0;
        for (int i = 0; i<n; i++){
            s += nums[i];
            s2 += (long long)nums[i] * (long long)nums[i];
        }
        // now we have to go with operation, now we have to make the two equation to the bot varaible 
        int val1 = s-sn ; //x-y
        int val2 = s2 -s2n;  //x^2 - y^2 till here value value is the difference
        val2 = val2/val1; //here we modify the value val2 to x+y 
        //by the operation , we have to done this 
        // back concept notebook me hai 
        long long x = (val1 +val2)/2;
        long long y = x-val1;
       return {(int)x,(int)y};
    }
};
