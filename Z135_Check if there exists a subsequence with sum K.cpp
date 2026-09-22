//key idea yadi ek bhi true hai toh matlab ek subsequence toh hai hi 
//power ste hi hai bus powerset mai sab print karna hota isme yadi hai toh return kardo ek dum simple 2 , application hai uski 
class Solution{
    public:

    bool f(int ind, vector<int>& nums, int k, int s, vector<int>& list, int n){
        if(ind == n){
            if(s == k){ //sum equal hai 
                return true;
            }
            else{//equal nahi hai 
                return false;
            }
        }
        //ek side pick ki hai
        list.push_back(nums[ind]);
        s += nums[ind];
        if(f(ind+1, nums, k, s, list,n) == true){
            return true;
        }
        s -= nums[ind];
        list.pop_back();
        //yadi nahi ki hai pick
        if(f(ind+1, nums, k, s, list,n) == true){
            return true;
        }
        return false;
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         int n = nums.size();
         vector<int> list;
        return f(0,nums,k,0,list,n);
    }
};
