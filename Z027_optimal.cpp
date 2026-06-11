//optimal approach - ab hume prefix and suffix concept use nahi krne because woh space complexity bdha rhae hai , ab hume do pointer se karna , jiss se kuch store krne ki zarrout na pde , ek baar usse increase krenge ek baar dusre ko , but usse kro traverse kregnge jpo small  or jiski buliding small hogi dono pointer me , yadi leftmax , pointer ki uss value se jada matlab paani bhrega and nahi toh nahi , tr
//we use smallest one approach phir woh automatically level maintain rakhega
//l and r sabse badi pe ek saath rukhenge
/*
1 konsa pointer chota , uske baad uska dekho leftmax nikal toh theek nahi nikalna hai , yadi nikalna hai woh bda hai current se toh badi buliding side kme toh paani bharega

*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int l = 0;
        int r = n-1;
        int leftmax =0;
        int rightmax = 0;
        while(l<r){
             if (height[l] <= height[r]) { //l chota l trabserse krega
            //left waale ki bulding choti hai 
            if(height[l]<= leftmax){
                // left max badi uss specific position se matlab depth hai tih pani bharega
                total += leftmax-height[l]; // ek ek baar pointer ko chlayeneg
            }
            else{
                leftmax =height[l];
            }
            l++;
        }
        else{
            if(height[r]<= rightmax){
                // right max badi uss specific position se matlab depth hai tih pani bharega
                total += rightmax-height[r]; // ek ek baar pointer ko chlayeneg, tjagah milti hai ehrei ki left me ye bukding , right me toh unke answer aajayega, kyuki jab ek move karenge toh second toh fix hoga toh do buliding mil gayi
            }
            else{
                rightmax =height[r];
            }
                r--; // r wali bulding choti toh ye tranverse kregi 
        }
        }
        return total;
    }
};
