//optimal approach - stack me daalte jaoo and jab daalo stack me toh dekho jo top hai yadi woh bda hai uss value se jisse daal rahe toh , top ko hta ke uss value ko daal do 
/*3 edge case 
1. k=n return mtlab sab kuch delete krenge
2. 00100 - toh isko 100 aise bnayenge
3. yadi inreasing value di hai 123456 toh last waale ko hta denge 
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int>st;
       // if(k == n) return '0';
        for(int i = 0; i<n;i++){
            while(!st.empty()  && k>0 && st.top()> num[i]){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        //stack me proper value dal gayi ab hume saare edge case handle krne 
        //3. handle krenge - yadi increasing hai
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        //ab jo bcha usko stack me usko ek variable me store kreke answer bhi dena hai
        string res = "";
        while(!st.empty()){
            //res = res + st.top()
            res.push_back(st.top());;
            st.pop();
        }
        //2. edge case case yadi aage value di hai toh 
        while(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }
        // Reverse to get the actual number
        reverse(res.begin(), res.end());
        
        // Edge case
        if(res.empty()) return "0";
        
        // Return the stored result
        return res;
    }
};
