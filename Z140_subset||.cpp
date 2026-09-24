//generate all subarra with is unique , hum same question ohele kar chuke hai 
//phele sort kro and next woh lena hai jo different ho
//unique lene hai toh har baar next me move karta hai
//ye jo skip karne jhai woh not taking part mai karne hai , dry kro sab clear ho jayega 

class Solution {
public:

    void f(int ind, vector<vector<int>>& ans, vector<int>&list, vector<int>& nums, int n){
        if(ind == n){
            ans.push_back(list);
            return;
        }
        //if we are taking
        list.push_back(nums[ind]);
        f(ind+1,ans,list, nums,n);
        list.pop_back();

        //koi fark nahi padta for loop use kro yaha ye waali use kro 
        //if we are not taking it 
        int j = ind + 1;
        while(j<n && nums[j] == nums[ind]){
            j++;
        }
        //skips ke baad ab next se move krega
        f(j,ans,list,nums,n);
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> list;
        int n= nums.size();
        f(0,ans,list,nums,n);
        return ans;
    }
};
