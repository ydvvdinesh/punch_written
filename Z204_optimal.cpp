//dono ke character ginege alag alag , yadi saaro ki frewuency same hai toh anagram hai , har charcter ki frequency ginege 
class Solution{	
	public:
		bool anagramStrings(string &s,string &t){
            int n = s.size();
            if(s.size() != t.size()){
                return false;
            }
            //hashing stores the frquency of the all charcters 
			int freqs[26] = {0};
            int freqt[26] = {0};
            //now mention their frequency
            for(int i = 0; i<n; i++){
                // writing the frequency  in hash array
                freqs[s[i]-'a']++;
                freqt[t[i]-'a']++;
            }
            //now jiska characterequal nahi ho , usko zero return kardo 
            //n tak nahi 26 tak jaoo kyuki charcter toh koi bhi bhi ho skata hai na 
            // yaha dono hash array dekhe jayenge kyuki unki frequency hi measure karni hai  
            for(int i = 0; i<26;i++){
                if(freqs[i] != freqt[i]){
                    return false;
                }
            }
            return true;
		}
};
