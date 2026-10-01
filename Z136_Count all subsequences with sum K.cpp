//according to striver bhai , return 1 if it satifies , if not return 0, in base case  and from all call they wikll return a balue from the both call add them up and give as answer
//both calls gives us a value , take or not take,that`s how it work in last we add the return answer of both call because call is adding that have sequence they tells uss total number of count from that path
class Solution{
    public:    	

        int f(int ind, vector<int>& nums, int k, int s, vector<int>& list, int n){
        if(ind == n){
            if(s == k){ //sum equal hai 
                return 1;
            }
            else{//equal nahi hai 
                return 0;
            }
        }
        //ek side pick ki hai
        list.push_back(nums[ind]);
        s += nums[ind];
        int leftcall_take = f(ind+1, nums, k, s, list,n);
        s -= nums[ind];
        list.pop_back();
        //yadi nahi ki hai pick
        int rightcall_take = f(ind+1, nums, k, s, list,n);
        return leftcall_take + rightcall_take;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
        int s = 0;
        int n = nums.size();
        vector<int> list;
    	return f(0,nums,k,s,list,n);
    }
};
