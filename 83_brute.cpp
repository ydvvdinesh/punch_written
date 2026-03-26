//same like allocation books problem, painter parition - minimum of maximum 
//brute approach 
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
        // maximum pages a student can have so will allocate books to all student without any disfuction
        // this loop is working on maximum pages , ki hum ek limit set krenge maximum pages ki ek person ke liye using this loop aur jaise hi usse maximum pages ki value pe sabko book allocate hogayi or saari toh woh answer hoga
        //this loop search space is from value of array to sum , because maxi se choti value studednt ki book ko hold nahi kr payegi
        for (int i = maxi; i<=sum;i++) {
            int countstudent = func(nums,i); //this function takes array , book details and the constraints (maximum pages set by us), it tells us how many student will allocate with the book
            if (countstudent <= k){ //yaha greater likha Because func() gives the minimum students required, and if that is ≤ k, we can always split further to use exactly k.
                return i; // maximum no of pages allocate kre hai , jisme sabko book allocate hui hai with all correct confiton
            }
        }
        return -1;
    }
};
