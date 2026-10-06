class Solution{	
	public:
    //compartor 
    static bool comp(pair<int,char>& p1, pair<int,char>& p2){
        // yadi phele ki frequency jaada mtab descending hai wohi chayiye tha
        if(p1.first > p2.first) return true;
        // yadi ulta huwa toh ascending ho jayega woh hame nahi we want descending toh true krenge 
        if(p1.first < p2.first) return false;
         // agar frequency same hai,
        // toh dictionary order mein character aayega
        return p1.second < p2.second;
    }

		vector<char> frequencySort(string& s){
            int n = s.size();
			//step -1 we declare pair which consist frequency and charcter and jiska frequency sabse jaada woh sabse aage aayenge and yadi dono ki frequency same hai toh diticonary ke hisab se aayenge then
            //1. declare a pair
            pair<int,char> freq[26];
            //now intilize with zero and charcter
            for(int i = 0; i<26;i++){
                freq[i] = {0, i+'a'};
            }
            //now put the frequency from looking at string
            for(int i = 0; i<n; i++){
                freq[s[i]-'a'].first++;
            }
            //after putting the value into array , now sort according to frequency in decreasing order yadi same hai toh dictionary
            //sort(freq.begin(),freq.end(), comp);
            sort(freq, freq + 26, comp); // becuse ye normal array nah haoi
            //sort ho gaya now store kr denge and return kar denge 
            vector<char> ans;
            for(int i = 0; i<26; i++){
                if(freq[i].first == 0){
                    break; // kyuki descending order mai chal raha hai , jiase hi zero pauche toh last tak hi zero rhega 
                }
                else{
                    ans.push_back(freq[i].second);
                }
            }
            return ans;
		}
};
