//brute
class Solution{	
	public:		
		void reverseString(vector<char>& s){
			int n = s.size();
            vector<char> dup(n,0);
            //loop to place the charcter of s vector in dup into reverse form
            for(int i = 0; i<n ;i++){
                dup[n-i-1] = s[i];
            }
            //now replace in the main charcter 
            for(int i = 0; i<n; i++){
                s[i] = dup[i];
            }
		}
};
