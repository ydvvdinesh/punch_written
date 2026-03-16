///bruteforce approach
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        for(int i = 0 ; i<n; i++){
            if (nums[i]==target){
                if(first == -1){
                    first = i; //we have to assign one time chayiye kitne same ho 
                }
                last = i; // yadi same value h toh last occurenece toh update hogi
            }
        }
        return {first,last}; // yadi nahi mila toh khud -1,-1 return ho jayega kyuki humne phele hi assign kr diya tha
    }
};


//another way to write 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1;
        int last = -1;
        for (int i =0; i<n;i++){
            if (nums[i]==target && first == -1){ //dono if alag alag mtlb dono run hogiindependent hai ek dusre ki
                first = i;
            }
            if (nums[i]==target){
                last = i;
            }
        }
        return {first,last};
    }
};
