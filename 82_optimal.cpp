bool canweplace(vector<int>& stall, int distanceatwhichweuseittoputconstraint, int cows){
    int p = stall.size();
    int countcows = 1; //countcows , it tell how many cordinate allocated to cow
    int last = stall[0];// current cows on ehich place
    for (int i =1; i<p;i++){//because 1 pe toh phele hi bitha di hai 
    if (stall[i]-last>=distanceatwhichweuseittoputconstraint){ // consecutive distanvce is greater than the distance at which we are checking to take it as constraint ki ye hogi toh next me jayegikyuki maximum chayiye
    //yadi maxi hai toh we put at there
    /*
    har distance me ek minimum distance nickali using consecutive distance after all distance we have to take the maximum of it
    */
    countcows++;
    last = stall[i]; // yaha bethiye 
    }
    }
    if(countcows>= cows) return true; // jitni thi sab baith cjuki hai
    return false;
}


class Solution {
public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int low = nums[0];
        int high = nums[n-1] - nums[0];;
        while (low <= high){
            int mid = (low +high )/2;
            if (canweplace(nums,mid,k) == true){
                ans = mid;
                low = mid +1; // because we are looking for the larger part
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};
