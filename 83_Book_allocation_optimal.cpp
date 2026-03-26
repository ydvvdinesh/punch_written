//optimal it same to painter paration, split largest
//this maximum tells kitne students ko allocate ki with constraints of maximum pages
int func(vector<int>& nums, int maximumpagesconstraintsetbyus){
    int n = nums.size();
    int student =1; // student tell us us on which we are or allocate to which onr
    int pagesstudenthave = 0; // first ke pass kuch nahi hota 
    for (int i =0; i<n;i++){
        if (pagesstudenthave + nums[i] <= maximumpagesconstraintsetbyus){
            //it means add it , nect one kyuki hum condition ke aandr hau
            pagesstudenthave += nums[i]; // same student ko book allocate krte raho
        }
        else{
            student++; //allocate to the next student
            pagesstudenthave = nums[i];//uske khud ke pages se start krdo
        }
    }
    return student; // jitne allocation woh khud gun legi
}
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN; 
        int sum = 0;
        for (int i =0; i<n;i++){
            maxi=max(maxi,nums[i]);
            sum += nums[i];
        }
        int low = maxi;
        int high = sum;
        int ans =-1;
        while(low<=high){
            int mid = (low+high)/2;
            int countstudent = func(nums,mid);
            if (countstudent > k) { low = mid +1;} //“If students exceed k, increase pages; if within k, try to minimize pages.”
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans; // opposite polarity
    }
};
