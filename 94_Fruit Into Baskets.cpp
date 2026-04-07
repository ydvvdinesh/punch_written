//our problem statement = longest subarray with 2 type of numbers/fruit
//brute approach - generate all sub array and put into set then check ki 2 hi unique element hai toh subaaray ko considered krenege and uski length return krnege , 2 se jada element h then we break up from that subarray
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = 0;
        int len =0; //find the length of subarray
        int k =2; //You only have two baskets,
        for(int i=0;i<n;i++){
            set<int> st; // reset for every i , important
            for (int j =i ; j <n;j++){
                st.insert(fruits[j]);
                if (st.size()<=k){
                    len = j-i+1;
                    maxlen = max(maxlen,len);
                }
                else{
                    break; // move to next subarray 
                }
            }
        }
        return maxlen;
    }
};
