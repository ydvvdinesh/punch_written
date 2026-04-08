//better
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r=0;
        int n = s.size();
        int maxlen =0;
        int hasha[26] = {0};
        int maxfre =0;
        while(r<n){
        hasha[s[r] - 'A']++; //kyuki captial me hi kaam krna hai
        maxfre = max(maxfre,hasha[s[r] - 'A']);//hash mapp me charcter daal bhi diye and max frequency bhi di
        int len = r-l+1;
        int changes = len -maxfre;
        //while a
        while(changes>k){ //shrink the window from left and isle saath jab move kro toh window se bahar gaya usko -ve krte jana 
        hasha[s[l] - 'A']--;; //decrease the frequency (ki kitni baar aaya )
        maxfre =0;
        for(int i =0 ; i<26;i++){
            maxfre =max(maxfre,hasha[i]);
        }
        l++;
        }
        if(changes<=k){
            maxlen = max(maxlen,len);
        }
        }
        return maxlen;
    }
};

//in better - for use
//in optimal - Optimal (if loop) → maxfre ko update karte hain but kabhi decrease nahi karte ✔️Reason → agar maxfre kam ho bhi gaya toh hume farak nahi padta ✔️
