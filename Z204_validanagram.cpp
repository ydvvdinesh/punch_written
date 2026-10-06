// anagram is the word , jo dure se bna le , jumbled word ko use karke same bna le
class Solution{	
	public:
		bool anagramStrings(string &s,string &t){
            if (s.length() != t.length()) return false;
			sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            if(s == t) return true;
            //otherwise sab false;
            return false;
		}
};
