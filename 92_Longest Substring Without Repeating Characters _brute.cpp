//brute approach = hashing, hash me store krwaoo and ja aa chuka usko toh agle character pe move krdo
//how to generate substring (like subarray) and 
/*
for (int i = 0; i<n; i++){
    string sub = "";
    for (int j = i; j<n;j++){
        sub = sub + s[j]; //it generates allsubstring 
    }
}
*/ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        for (int i = 0; i<n;i++){
            int hasha[256] = {0}; //string has 256 charcters amd hash array declr=artion is same like the old one
            for (int j = i; j<n;j++){
                if (hasha[s[j]] == 1){ // yadi usse jagah pe phele se element h toh we break and we will move to next one
                    break;
                }
                else{
                    int len = j-i+1;
                    maxi = max(maxi,len);
                    hasha[s[j]] = 1; //in starting toh zero h toh 1 hi assign krte chlenge
                }
            }
        }
        return maxi;
    }
};

//complexity - time - o(n^2) because do loop chal rahi hai
// space - o(256)- because hash utne hi store krega na 
