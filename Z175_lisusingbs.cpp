//lis using binary search , bus lower bound nikaalne me use krenge 
//this is breaking the rule of subsequence , this method is only give us the length of lis , but it can`t return it break the rule 
//go with the rewrite part yadi temp maio bda hai index pe and hum koi chota mila usse toh hum usko replace kar denge 
class Solution {
public:
    int LIS(vector<int>& nums) {
      vector<int> temp;
      int n = nums.size();
      temp.push_back(nums[0]);
      //phela toh bina dekhe push kardo because ussi se compare karna hai 
      for(int i = 1; i<n; i++){
        if(nums[i] > temp.back()){ // toh sahi woh rewrite nahi karega uske aage lgega
            temp.push_back(nums[i]);
        }
        else{ //yadi bada hai toh usse rewrite krega , and hum uske lowerbound se rewrite because lowerbound means the index which equal to greater than that value , bus yahi hum binary search ka use krenge simple 
            int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
      }
      return temp.size();
    }    
};
