class Solution{	
	public:		
		bool palindromeCheck(string& s){
			int n = s.size();
            int l =0;
            int r =n-1;
            while(l<r){
                if(s[l] != s[r]){
                    return false;
                }
                l++;
                r--;
            }
            return true;
		}
};
