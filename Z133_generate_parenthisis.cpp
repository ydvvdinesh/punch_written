//ek dum easy har ek possible case bnana hai, har case mai uske do sub parts bnate chle jayenge, one closing waala and dusra closing waala , jab closing waala add , ho toh closing waala increase kar dena and jab opening waala ho toh openning waala add kar dena 
//do condition hai ek toh opening hmesha cloisng se bda rhega in balanced question and jab opening and closing barbar hongi tabhi string bnegi 
//jab opening , n se jada ho jaye toh hum glata hai
// hum n given hai toh 2n place bna lenge and phir khelenge
class Solution {
public:
    void fun(int n, string s, int open, int close,vector<string>& ans){
      if(open>n) return; 
      //matlab balanced string
      if(open + close == 2*n && open  == close){
        ans.push_back(s);
        return;
      }
      //phele hum open ko position mai put krenge
      fun(n, s+'(', open +1,close, ans);
      // then closing ko and tabhi tabhi closing choti hai open se 
      if(open>close){
        fun(n, s+')', open,close +1, ans); // opening ke saath iss call se recursive pe jayenge
      }
    }

    vector<string> generateParenthesis(int n) {
      vector<string> ans; //stores the answer 
      string st = "";
      int opening = 0;
      int closing = 0;
      fun(n,st,opening,closing,ans);
      return ans;
    }
};
