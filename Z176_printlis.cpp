//concept sirf 8 minute ka hai but code thoda sa hard hai woh dhyan rakhna 
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1); //vectpr that stores the maximum no lis end at that index 
        vector<int> hasharray(n);//this stores last konse index pe subsequence end ho hai and jaada end hai ho rahe hai matlbab maximum or previous store krega bro
        int lastindex = 0;
        int maxi = 0;
        for(int ind = 0; ind<n; ind++){
            hasharray[ind] = ind;
            for(int prev = 0; prev<ind;prev++){
                if(arr[ind] > arr[prev] && 1 + dp[prev]>dp[ind]){
                    dp[ind] = 1 + dp[prev];
                    hasharray[ind] = prev;
                }
            }
            if(dp[ind] > maxi){
                maxi = dp[ind];
                lastindex = ind;
            }
        }
    //yaha tak and dp and hasharray dono bhar chuke hai now backtrack karna hai 
    vector<int> temp;
    temp.push_back(arr[lastindex]);
    while(hasharray[lastindex] != lastindex){
        lastindex = hasharray[lastindex];
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(), temp.end());
   return temp;
    }
};
