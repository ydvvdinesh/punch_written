// digit pakdo and uske saare aphbets ko dusre dusri digits ke saath combine  kardo and saare possible set likh do best exaple catersian multiplication of set 
//thoda code differnet ha warna concept ek dum easy hai 
class Solution {
public:

    void f(int ind, string digits, string str, vector<string>&ans, string combos[]){
        if(ind == digits.size()){
            ans.push_back(str);
            return;
        }
        //we have to take all thing , toh not take ka toh sawal hi nahi aata 
        //now we have to traverse the alphabet and when to all , so we use them 
        int number = digits[ind] - '0';
        // count ke uss index ka size count[ind].size())
        for(int i=0; i<combos[number].size(); i++){
            //now caal the recuro=ive function he will automatically go to all possiblites 
            f(ind +1,digits,str +combos[number][i],ans, combos);
        }
        //ye loop albhaest ke liye hai , jaise ek phele index ke saare parts lelenge toh hu next pe reach kar jayenge 

    }
    
    vector<string> letterCombinations(string digits) {
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string str;
        f(0,digits,str,ans,combos);
        return ans;
    }
};
