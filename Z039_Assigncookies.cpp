//greedy algoritham - sabko thoda dedo taaki hamare liye jada bach jaye
//or jp aaye usko sabse chota assign karte jaoo
//at most sab bacho ko ek cokkie toh milte try ye karni hai yadi mili toh aacha nahi mili toh bhi aacha
// g is the array of children and g[index] have greed value and s is the array of cookis 
//we go with two pointer ki sabse kam assign kre , toh sabse phele array sort kro
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l = 0; //this isthe index of cookies array
        int r =0; //children array
        // r index only tabhi move hoga jab jab bache ko cookie assign ho jayegi and assigning ki condition is greed factor se size bda ho ya equal ho uss particular children ka cookie ka 
        int n = g.size();
        int m = s.size();
        //ab tab tak dekhenge jab tak saari cookies traverse na ho jaye ya check ho jaye 
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //lets start transverse cokkies array , but remeber ye bhi dekhna hai kahi sab baacho ki greed jada toh nahi hai size 
        while(l<m && r < n){
            if(g[r] <= s[l]){
                r = r+1;
            }
            l=l+1;
        }
        return r;
        //why r becuase we are using zero based indexing , jaha r last me standig rhega uske phele ke sab bacho ko assign ho chuka hoga na
    }
};
