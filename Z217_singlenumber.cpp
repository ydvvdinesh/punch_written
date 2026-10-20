//we are suing map to remeber the frquency and later we will return it 
class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int n = nums.size();
        unordered_map<int,int> mpp;
        // traverse to put into map
        for(int i = 0; i<n; i++){
            mpp[nums[i]] = mpp[nums[i]] +1;
        }
        //on first the map will store the number then its freqnecy
        //now traverse trhough map
        for(auto it : mpp){
            if(it.second == 1){
                return it.first;
            }
        }
        return 0;
    }
};
