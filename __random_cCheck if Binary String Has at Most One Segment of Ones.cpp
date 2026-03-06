//out of the bond 
//logic - contiuous aane chayiye like 11001100 , 101010 nahi chlenge 
class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '1' && s[i-1] == '0'){
                return false;
            }
        }
        return true;
    }
};
