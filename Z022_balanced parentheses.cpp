//approach - What does "order" mean? The bracket that opens last must close first.
/*
1.last opening bracket ko stack and me store kro and fir uske top se closing waale ko compare kro
2. jaise hi closing bracket ho toh check krlo same type hai ya nahi .
yadi hai toh balanced and stack empty ho jayega ( but ek case in first jaha yadi stack khaali , koi opening nahi hai toh unbalanced)
*/
class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        //lets traverse with zero based indexing
        for(int i =0 ; i< s.size();i++){
            //opening bracket encounter
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                //yadi opening nahi mtlb stack , empty rhega and order bhi nahi bndega
                if(st.empty()) return false;
                // now we have to compare with the top
                char ch = st.top();
                st.pop();
                // ab closing ka top ke saath comparison hoga 
                if((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') ||(s[i] == '}' && ch == '{') ) {
                    //return true; ye first pair check krke dekh rha hai , saare check krne and lsat waala empty khud reply de dega
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
