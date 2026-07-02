//bruteforce approach yadi opening bracket aaye toh count ko 1 se increase krdo otherwise 1 decrease krdo and yadi asterik aaye toh teen case hai  opening , closing, blank, yadi count last me zero hai toh string valid hai 
//recursive approach se jaate then we go with optimal one ofrange approach 
class Solution {
public:

    bool solve(int index, int count, string &s){
        int n = s.size();
        if(count < 0) return false; //) ye case phele hi closing aajaye
        if(index == n){
            return (count ==0);
        }
        //if opening one
        if(s[index] == '('){
            return solve(index+1, count+1, s);
        }
        // if closing one 
        if(s[index] == ')'){
            return solve(index+1, count-1, s);
        }
        // if astrik toh teen branch bnegi yadi ek bhi dahi nikali then true 
        /*if(solve(index+1, count+1, s) || solve(index+1, count-1, s) || solve(index+1, count, s)){
            return true;
        }*/
        return solve(index + 1, count + 1, s) ||   // treat as '('
               solve(index + 1, count - 1, s) ||   // treat as ')'
               solve(index + 1, count, s);         // treat as empty
    }


    bool checkValidString(string s) {
       return solve(0,0,s);
    }
};
