class Solution{	
public:		
    string largeOddNum(string& s){
        int n = s.size();
        int j = -1;
        //finding odd digit from the back 
        //way to convert from the string to number 
        for(int i = n-1; i>=0; i--){
            if((s[i]- '0') % 2 == 1){
                j = i; // we find the end index of word, now from staring to end everything will be is the odd digit, bus starting zero nahi hogi usse next one hoga 
                break;
            }
        }
        // If there is no odd digit, no odd number can be formed 
        if (j == -1) { 
            return ""; 
        }

        int startindex = 0;
        int i = 0;
        while(i<n){
            if(s[i] != '0'){
                startindex = i;
                break;
            }
            i++;
        }
        return s.substr(startindex, j-startindex+1);
    }
};
