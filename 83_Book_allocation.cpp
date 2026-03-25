//optimal approach = 
//👉 barrier = maximum number of pages a single student is allowed to read
// thhis function is return that allocation is possible or not in given number of student with that condition
bool allocation_possible(vector<int>& nums, int barrier, int noofstudent){
    int n = nums.size();
    int student_allocation = 1; // the allocation of pages will start from the first student
    int pages = 0; //current pages assigned to the current student
    for (int i =0; i<n;i++){
        if (nums[i]>barrier) return false; 
        if (pages + nums[i] > barrier){ //jaise hi current pages + nums[i] mtlb ab dusre ko assign krna 
            //time to allocate the book to next student
            student_allocation++;
            pages = nums[i]; // reset for new studentst 
        }
        else{
            pages += nums[i]; // barrier se bde nahi hai toh again and again jodte raho brother
        }
    }
    if (student_allocation > noofstudent ) return false;
    else {
        return true;
    }
}

class Solution {
public:
    int findPages(vector<int> &nums, int m)  { // m = no students, // array[size] = no of books and at their place no of pages 
        int n = nums.size();
        int mini = nums[0];
        int sum =0;
        for(int i = 0; i<n;i++){
            sum += nums[i];
        }
        int ans = -1; // kuch nahi huwa toh 
        int low = mini;
        int high = sum;
        while(low<=high){
            int mid = (low +high)/2;
            if(allocation_possible(nums,mid,m)== true){
                ans = mid;
                high = mid-1; // we have to look for the minimum
            }
            else{
                low = mid +1;
            }
        }
       return ans;
    }
};
