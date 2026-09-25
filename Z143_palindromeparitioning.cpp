//stirng la partition karna hai bro  esay hai , bus jab parititon kro toh pandlidrome honi chayiye 
//now , isme index ke saal form liye , jayenge , jaise last waala me sab letter liye the isme sab index se khelna , now jaha ho waha se n-1 tak jaana hai, har baar ans woh saapossible case lene hai , phele check karna hai, ki pandlidrome hai ki nhai jo hai usse le lena hai , jo naahi hai usse mat lena 
class Solution {
public:
//palindrome function

    bool check(string s, int left, int right){
        while(left <= right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
        return true;
    }

    void f(int ind, string s, vector<vector<string>>& ans, vector<string>& list, int n){
        if(ind == n){
            ans.push_back(list);
            return;
        }
        //now har pe jaana hai using that index 
        for(int j = ind; j<n;j++){
            if(check(s,ind,j) == true){ //we are checking palindrome here, yadi palindrome hai toh hum usko answer mai add krenge and we did, kyuki woh bhi string partitioning hi ho rahi hai 🤣
                list.push_back(s.substr(ind,j-ind+1));
                f(j+1, s, ans, list,n);
                list.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> list;
        int n = s.size();
        f(0,s,ans,list,n);
        return ans;
    }
};
