//ek dum easy hai . first word ko last word me convert karna hai , using the given word list , jab convert jo haye toh total number of steps btane hai , that is the answer
//approach - we take the first word and uske har letter ko a se z replace karenge , har letter ko , jab ek ki replacing hogi toh do static rhenge, and jaise hi koi word milege jo wordlist me hai toh hum usko queue me daalenge and , and jab jab hum q se cheeze remove karenge toh ye steps repeat krenge , last me hum manzil pe pauch jayenge and we got the no of step , har baar milne par ya queue me jaay toh ek step increase hoga
// we are using bfs because level by level transformation kar rahe hai na 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // we are taking the set that have wordlist inside it , now question why so simple answer is , set gives us unorder thing , jisse doodne me cheeze aasan ho jayengi
        unordered_set<string> st(wordList.begin(),wordList.end());
        // set me sab kuch now 
        queue<pair<string,int>> q;
        //pushing the first word and starting the bfs
        q.push({beginWord,1});
        // jab push ho jaye toh set se remove kardo kyu hi bheed rakhni warna time complexity increase krega 
        st.erase(beginWord);

        // now ye steps repeat karne jab tak queue khali na ho tab tak
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            // now jo queue se niklega uske letter pe a to z karke dekh jayega
        //ye main step jo answer dega 
        if(word == endWord) return step;

            for(int i =0; i<word.size();i++){
                char orginal = word[i];
                // now replace and check
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;//here we are replacing
                    if(st.find(word) != st.end()){
                        q.push({word, step+1});
                        st.erase(word);
                    }
                }
                // after replcing , jaise word tha wohi chayiye kyuki uske next letter bhi traverse karne hai 
                word[i] = orginal; 
            }
        }
        return 0;
    }
};
