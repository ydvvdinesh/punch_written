//better appoach = take elemnt from array push to map , map includes number and the frequency , then check map`s size is greater than k  or not , if yes then aukkat me laoo , window ko left se shrink kro and continuously decrease the frequency whn moving to right till <= 2 , jaha 3rd number hta uske baad l shift ho jayega simple 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l=0, r=0;
        int k =2;
        int maxlen =0;
        int len =0;
        map<int, int> mpp; //one is number, another is frequency
        while(r<n){
            mpp[fruits[r]]++; //in starting insert every element in the mapp
            //yadi element jada at most k size se , toh unko aukaat me laoo by shrinking the window from left , till jak k element na bche subarray me
            if(mpp.size()>k){
                while(mpp.size()>k){ // this loop is for the moving l and also mapp operations
                    mpp[fruits[l]]--; //decrease the frequency
                    if(mpp[fruits[l]] == 0){
                        mpp.erase(fruits[l]); //jaise frquency zero remove the element from the mapp and l find new location to new tyoe element
                    }
                    l++;
                }
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
