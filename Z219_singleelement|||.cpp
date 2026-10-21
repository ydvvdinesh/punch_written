//mapp waala way
class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			int n = nums.size();
            unordered_map<int,int> mpp;
            vector<int> ans;
            for(int i = 0; i<n; i++){
                mpp[nums[i]] = mpp[nums[i]]+1;
            }
            //now traverse into map 
            for(auto it : mpp){
                if(it.second == 1){
                    ans.push_back(it.first);
                }
            }
            sort(ans.begin(),ans.end());
            return ans;
		}
};
