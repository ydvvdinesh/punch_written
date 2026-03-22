//optimal

int totalsum(vector<int>& nums, int divisor){
    int sum = 0;
    // ceil(nums[i]/divisor) = (nums[i] + divisor - 1) / divisor
    for (int i =0; i<nums.size();i++){
        sum = sum + (nums[i] + divisor - 1) / divisor;
    }
    return sum;
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
    for (int i = 0 ; i<n;i++){ // for finding the maximum
        maxi = max(maxi,nums[i]);
    }
    int low = 1;
    int high = maxi;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
    int munni = totalsum(nums,mid); // munni is the variable which recalling the function on the array nums and with divisor mid
    if(munni<=threshold){
        ans = mid;
        high = mid-1;
    }
    else{
        low = mid +1;
    }
}
    return ans;
    }
};
//linear search me i move krta and bineary search me mid and , pheli condituion answer deti hai and baaki search pace ka kaam krti hai 
