//brute force approach 
//logic - 2 p0inter se hoga 
//step-1 ek element khud ka bhi subarray hoga and jo usse next h uska bhi and jo usse next hai uska upto last elements of array, now simiarly aagle index(1) pe aate hai wo khud bhi and aur usse usse including krte huwe saare 
//step -2 3 loop ka khel hai first loop element pe rhegi and while another one iterate kregi and last waali generate array ka sum nikalegi jo hume given k se compare krenge , equal h toh len hum len varable and j-i+1 obervation se pta lga lenge
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i<n;i++){
            for (int j = i;j<n;j++){
                int sum =0;
                for (int x = i ; x<=j;x++){
                    sum = sum + nums[x]; // sum isliye compare krwana hai yadi wo given ke equal toh that we get our sub array correct and then hum usko easily length nikal lenge or 
                  /*Hum har generated subarray ka sum calculate karte hain.
Agar kisi subarray ka sum given value k ke equal hota hai, to wo ek valid subarray hota hai.
Iske baad hum us subarray ki length easily nikaal sakte hain.”*/
                }
            if (sum==k){
              //  len = max(len,j-i+1); if asking for the length of longest sub array 
              count = count +1;//if asking for toal no of sub array
            }
            }
        }
        return count;
    }
};
