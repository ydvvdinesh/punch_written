//optimal approach without using the lower bound and upper bound approach
//if interviewer said he want to go with the approach of only bineary search no lower and upper bound used
//for finding the first occurence 
int phela(vector<int>& nums, int target){
    int first = -1;
    int p = nums.size();
    int low = 0;
    int high = p-1;
    while (low<=high){
        int mid = low + (high - low) / 2; // to avoid the overglow case
        if(nums[mid] == target){
            first = mid;
            high = mid-1; // imp step yadi same pe aayi toh hum left me jayenege kyuki first occurene wahi milegi
        }
        else if(nums[mid]>target){
            high = mid -1;
        }
        else {
            low = mid +1;
        }
    }
    return first;
}
//for last occurene
int aakhir(vector<int>& nums, int target){
    int a = nums.size();
    int last = -1;
    int low = 0;
    int high = a-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if (nums[mid] == target ){
            last = mid;
            low = mid+1;//right me search krenge because hume last occurenece right me hi milegi
        }
        else if(nums[mid]>target){
            high = mid -1; //search space target ke reference se dekhenge 
        }
        else {
            low = mid +1;
        }
    }
    return last;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int one = phela(nums,target);
        int end = aakhir(nums,target); // without int karna , kyuki isme value daalni hai
        // agar first hi nahi mila → target exist nahi karta
        if (one == -1) return {-1, -1};
        return {one,end};
    }
};
