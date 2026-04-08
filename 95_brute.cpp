//brute approach 
/*
aim - find longest repeating substring and we flipflop at most k charcter,  what we want

Step -1 generate all substring, and we have to find the minimal appearcence charchter in that substring , kyuki hume minimal operation krne hote h toh hum minimal conversion ki traf jayenge , uska track rakhne ke liye hum hash array use krenge
formula - minimal conversion or least no of that charcters = total length - max frequency
step -2 changes <= k, hum uss time ki maximum length de denge 
step -3 other wisw we break out 
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen =0;
        //generate all substring 
        for (int i =0;i<n;i++){
            int hasha[26]={0}; // total uppercase charcter 26 hote hai 
            int maxfre = 0; //reset everytime
            for (int j =i;j<n;j++){
                hasha[s[j]-'A']++;//jitni occurence utna aayega
                maxfre = max(hasha[s[j]-'A'],maxfre);//s[j] is a character like 'A', 'B' → ASCII value (~65–90)
                int len = j-i+1;
                int changes = len - maxfre ;//kitne charcter change krne sabse longest substring bnane me 
                if(changes<=k){
                    maxlen = max(maxlen,len);
                }
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
};
