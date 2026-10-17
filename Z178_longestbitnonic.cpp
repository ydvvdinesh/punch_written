//bitonic - means subsequence which is inresaing first and then decreasing in last 
// approach - we are creating two array one is start from first and another one is starts from backward. and in dp1 we will store the no fo subsequence end at that index but by traversing from the front and in thedp2 we will start the trversing from back that meanslogically if we think from left one is increasing and another is decreasing and if we add them and -1 from there it gives the bitonic array and we will return that array  
//after merging dono me se jo bhi jada wohi aayega 
class Solution {
  public:
    int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        int maxi = 0;
        //from front 
        for(int ind = 0; ind<n; ind++){
            for(int prev = 0; prev <ind; prev++){
                if(arr[ind] > arr[prev] && 1 + dp1[prev] > dp1[ind]){
                    dp1[ind] = 1 + dp1[prev];
                }
            }
        }
        //from backward 
        for(int ind = n-1; ind>=0; ind--){
            //ye prev back se aayega bus ye dhyan rakhna
            for(int prev = n-1; prev > ind; prev--){
                if(arr[ind] > arr[prev] && 1 + dp2[prev] > dp2[ind]){
                    dp2[ind] = 1 + dp2[prev];
                }
            }
            //hum issue loop mai solve kar denge otherwise hame o(n) aur lgegi
            maxi = max(maxi,dp1[ind]+dp2[ind]-1);
        }
        return maxi;
    }
};
