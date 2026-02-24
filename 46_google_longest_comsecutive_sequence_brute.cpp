//brute approach 
class Solution {
public:
    bool ls(vector<int>arr, int num){
        for (int i = 0; i<arr.size(); i++){
            if(arr[i]==num){
                return true;
            }
            return false;
        }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int lomgest = 0;
        for (int i = 0;i<n;i++){
            int x=nums[i];
            int count = 1;
            while (ls(nums,x+1) == true){ // ye cheeze kru matalb we get our consecutive and ab next ko check kro
                x=x+1;
                count = count +1;
            }
            longest = max(longest,count);
        }
        return count;
    }
};
