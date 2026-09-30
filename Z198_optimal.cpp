//use to pointer approach - do pointer rakho ek first pe ek last pe and dono se chalo , exact position pe swapping karte jaao
class Solution{	
	public:		
		void reverseString(vector<char>& s){
			int n = s.size();
            int l = 0;
            int r = n-1;
            while(l<r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
		}
};
