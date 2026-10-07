//brute force approach 
class Solution {
public:
    string reverseWords(string s) {
       int n = s.size();
       vector<string> list;
       //step 1 find me the first index where a leer of a word is present 
       int i = 0;
       while(i<n){
        while(i<n && s[i] ==' '){
            i++;
        }
        // If no word is found, break 
            if(i >= n) break;
            ///imppppppppppppp edgeeeeee caseeeeeeee
        //jab tak milte rhenge space tab tak chlta rhega and jaise hi leettet vaise rukega and hum uska startt point note kar lenge 
        int start = i;
        //ab ending of word ke liye hum space dooondenge jaise hi letter ke baad space aaya toh woh letter end hojayega 
        //jab tak space nahi aayega itne chlta rhega , aate hi while loop break uss index ke peeche waala last index 
        while(i<n && s[i] != ' '){
            i++;
        }
        int end = i-1;
        //ab pura word aachuka hai so list me daal denge 
        list.push_back(s.substr(start,end - start + 1));
       }
       //But substr() takes: substr(start, length) not substr(start, end_index)
       //once list filled now list ke last word lenge then uske baad then uske baad aise chlta rhega and unke word ke beech space bhi dena hai woh yaad rakhna hai 
        string ans ;
        for(int i = list.size()-1;i>=0;i--){
            ans += list[i];
            //now add space
            if(i != 0){
                ans += ' ';
            }
        }
        return ans;
    } 
};
