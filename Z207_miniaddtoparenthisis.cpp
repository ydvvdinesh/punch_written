//ek dum easy hai , logic simple hai giet rid of balanced part and ab open close bache jo balcend nahi hai toh unke ke reversal ghin lo , and jinka sample behaviour like 3 open hai toh usme yadi ek ka reversal karde toh 1 pair balane ho gaya toh 3 me se ek ki open , kyuki do ka toh pair bnaya same in closing 
//so we created a fromula = open/2  + open%2 + close/2 + close%2 it gives us toatal number of minimum reversal jo maine concept btaye ussi se hi kiya hai 
// jab hum balance dekhe toh usme aisa hota hi har closing ke liye opening hogi , yadi opening nahi toh closing ka number increase hota jayega and yadi  opening hai toh usse pair bna lenge toh hum open ka number ghata denge that means balance hai woh 
class Solution {
public:
    int countRev (string s) {
        int n = s.size();
        int open = 0; //'('
        int close = 0; //')'

        //base case ye sab tabhi ho skta hai jab total number of brackets even ho , yadi odd toh kabhi balance nahi ho payegi 
        if(n%2 == 1) return -1;
        for(int i = 0; i<n; i++){
            if(s[i] == '('){ //opening 
                open++;
            }
            else{//closing
                // har closing ke liye opening check hogi
                if(open>0){
                    open--; //toh balanced ho gaye iska ye matlab hai 
                }
                else{
                    //toh sirf closing badhegi
                    close++;
                }
            }
        }
        //when loops completes it gives us  close and open bracket numbers 
        int minireversal = open/2 + open%2 + close/2 + close%2;
        return minireversal;
    }
};
