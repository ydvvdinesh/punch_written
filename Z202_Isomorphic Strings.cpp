///2 baar dekh lena concept bhi thoda sa confusing 

//dono string ko yaad rakhna pdega , we all know yadi koi cheeze remeber karni hai toh hum hashmap or hashing or hasharray use karna hi pdega 
//dono string ko daalo alag has
//isomorphicString condition 0 dono ka same size hona chayiye and mutliple mapping nahi hogi domain ke element ki , one to one function ki traay kaam krega 
class Solution {
public:
    bool isomorphicString(string s, string t) {
        // Both strings must have same size 
        if(s.size() != t.size()) { 
            return false; 
        }
    	// declaration of hasharray 
        int smap[256] = {0};
        int tmap[256] = {0};
        for(int i = 0; i<s.size(); i++){
            //condition jo niche menton ki hai
            //a)yadi nahi hai toh hum aage mapping check krenge 
                ///b attach to someone else, mutli mapping hui 
//smap[s[i]] != 0 means s[i] was already seen.
//tmap[t[i]] != 0 means t[i] was already seen.
//smap[s[i]] != i + 1 || tmap[t[i]] != i + 1
//This asks: Are they NOT mapped to the current same position?
//simple for 
           if (smap[s[i]] != tmap[t[i]]) return false;

            //mapping tabhi hogi wab woh upper ki condition ko krega that is koi elemen bachna nahi chayiye and , yadi ek element uss index ko chod ke kisi aur se map hai toh 
            smap[s[i]] = i + 1; // why +1 for just safety reson ki answr mile hi mile 
            tmap[t[i]] = i + 1;
        }
        return true;
    }
};
