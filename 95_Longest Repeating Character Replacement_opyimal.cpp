//optimal - while ki jagah , if krnege woh chlat jata and automatically saare cover hojate , hum jo ek baar maxlen aayi uska differnce rakh ke move krte rhte hai 
/*
❌ While version:
while (window invalid) {
    shrink fully until valid
}
👉 Window ko forcefully valid banate ho
✅ Optimal (if version):
if (window invalid) {
    shrink only once
}
👉 Window ko temporarily invalid rehne dete ho
*/
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
        /*💡 Magic Kaha Hai?
👉 Jab tum if use karte ho:
Window invalid ho sakti hai
BUT next iterations me r++ hone se:
ya toh maxfre badhega
ya window adjust ho jayegi
👉 So window khud theek ho jaati hai (self-correcting)*/
        if(changes>k){ //shrink the window from left and isle saath jab move kro toh window se bahar gaya usko -ve krte jana 
        hasha[s[l] - 'A']--;; //decrease the frequency (ki kitni baar aaya )
        l++;
        }
        if(changes<=k){
            maxlen = max(maxlen,len);
        }
        r++;
        }
        return maxlen;
    }
};

//in better - for use
//in optimal - Optimal (if loop) → maxfre ko update karte hain but kabhi decrease nahi karte ✔️Reason → agar maxfre kam ho bhi gaya toh hume farak nahi padta ✔️
