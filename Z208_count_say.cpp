//isme hume frequency_digit save karni hai
//ex - 21 ans - 1211 and 1211 = ans = 111221 , yadi jab group me hai idnetical toh ek baar hi leekha jayega 
class Solution {
  public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = countAndSay(n-1);
        //we will start from index one , because we have to compare with the previous one
        //why count =1 , when we are starting from index 1 then we already counted index 0 
        int count = 1;
        string res;
        //yaha dhyan rakhna na aaya
        for(int i = 1; i<prev.size(); i++){
            //yadi same hai toh count increase kro
            if(prev[i] == prev[i-1]){
                count++;
            }
            //yadi nahi hai toh naye element se start kro with reset count but piche waale ko store karlo
            else{
                //kyuki phele frequency phir digit 
                res += '0' + count;
                res += prev[i-1]; //isko zero mai badalne ki jaoorat nahi hai phele hi badal chuka hai
                count = 1;
            }
        }
        //ye jo lopp hai ye n-1 tak chali uske baad compare nahi kar payenge toh last waale ko direct add kar denge 
            res += '0' + count;
            res += prev.back(); // iske jagah ye runtime error dde raha tha  res += '0' + prev[i-1];
        return res;
    }   
};
