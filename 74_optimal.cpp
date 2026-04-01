//optimal
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int n = nums.size();
        if (n==1) return 0; // if array has single element
        //we have the -infinte to array to - infinite
        if (nums[0]>nums[1]) return 0;
        if (nums[n-2]<nums[n-1]) return n-1;
        // ab array humne 1 to n-2 kr diya
        int low = 1;
        int high = n-2;
        while (low <= high){
            int mid = (low +high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){ // bineary me first condition hi answer degi
                return mid;
            }
        // humare mid mtlb jaha hum khde , last element se check krenge , yadi mid last element se bda that means that are in increasing sorted curve so peak dusri curve pe milega because peak aane ke baad curve down hogi hai , jidr peak hoga hum chle jaye and mid waale part ko eliminate kr deneg
        //on left curve
            else if(nums[mid]>nums[mid-1]){ //jaha bda hai uss direction me hum chlenge
                low = mid +1;
            }
            // on right curve
            else if(nums[mid]<nums[mid-1]){
                high = mid -1;
            }
            // this condtion is only we have multiple peaks , because at valley hmari loop infinte ho jayegi jab low and high stuck ho jayegnge toh hume bus use time kisi bhiek pointer ko move krwa dena hai
            // ex - 1,5,1,2,1
            else{
                low = mid+1;
                //high = mid-1; koi bhi move krwado
            }
        }
        return -1;

    }
};
