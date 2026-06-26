//optimal approach - jab tak quoitent 1 nahi aata tab tak divide krte rhe and remainder note krte raho and jasie hi quoitent 1 aa jaye , toh us quoitent ko include karke ek ek number likh and usko reverse kardo // 2 ko haar baar naye number se divide karna hai jo quoitent bhi hoga
class Solution {
public:
    string baseNeg2(int n) {
        string res;
        while(n != 1){
            if(n %2 == 1){
                res += "1";
            }
            else if(n%2 == 0){
                res += "0";
            }
            n = n/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
