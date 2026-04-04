//optimal approach - two pointer se jayenga and naki saare case generate krwa ke 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxi = 0;
        //hash map ki jagah hash array use krenge becasue log(256) nahi krna 
        int hasha[256];
        for (int i= 0; i<256; i++){
            hasha[i] = -1; //intiliaze -1 to every index
        }
        //dono pointer ek hi index se start honge
        int l = 0;
        int r = 0; // r move krenge and l stand pe rhega
        while(r<n){
            if (hasha[s[r]] != -1){ // the element exist in the array
                // and we know we get our answer between l and r rember this thing
                if (hasha[s[r]] >= l){ //kyuki l bhi toh right me hi move krega and woh thodi left me jaake range krab krega
                l= hasha[s[r]] + 1 ; // yadi duplicate charcter mila toh hum l ko duplicate charcter ke previous index ke aage le aayenge by one place 
                }
            } 
                int len = r-l+1;
                maxi = max(maxi,len);
                hasha[s[r]] = r; //  s ke r ki jagah new r assign hoga
                r++;
        }
        return maxi;
    }
};
