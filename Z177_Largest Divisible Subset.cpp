//bilkul same hai print lis ke bas usme condiitionthi ki piche waala chota hoga aage waale se ki isme aage waala divisble hoga opiche waala se so obvious hai divide tabhi hoga bde bda hoga toh hum given array ko sort kakre print lis lga denge 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> nums) {
      int n = nums.size();
      int maxi =0;
      int lastindex = 0;
      sort(nums.begin(),nums.end());
      vector<int> dp(n,1);
      vector<int>hash(n);
      for(int ind = 0 ; ind<n; ind++){
        hash[ind] = ind;
        for(int prev = 0;prev<ind;prev++){
            if(nums[ind] % nums[prev] == 0 && 1+dp[prev] > dp[ind]){ //yaha hi change hoga , usme comparsion ka game hot ahai isme divisblity ka khel hota hai
            dp[ind] = dp[prev] + 1;
            hash[ind] = prev; //yadi mila toh last waale ka index note kar lenge 
            }
        }
        //ye for getting the index which gives maximum length to us 
        if(dp[ind]>maxi){
            maxi = dp[ind]; // ye index store krega 
            lastindex = ind; // last index stores the index where we get the maximum value 
        } 
      }
      vector<int> temp;
      while(hash[lastindex] != lastindex){
        temp.push_back(nums[lastindex]);
        lastindex = hash[lastindex]; //isme index pe value store krenge , hash me bhi index hi as value store hai 
      }
       temp.push_back(nums[lastindex]);
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
