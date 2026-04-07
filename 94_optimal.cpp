//optimal approach -  bas jo inner while hai usski jagah ek concept daal denge which is Even though we shrink only once,
//we do NOT update max length when invalid, So window can be temporarily invalid, but:, We don’t count it, Next iterations automatically fix it
/*
while version: “Make window valid first, then move ahead”
if version: “Move ahead, window will fix itself gradually”
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l=0, r=0;
        int len =0;
        int maxlen = 0;
        int k =2;
        map<int,int> mpp;
        while(r<n){
             mpp[fruits[r]]++;
            if(mpp.size()>k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size()<=k){
                len = r-l+1;
                maxlen = max(len,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};
