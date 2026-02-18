//Dutch National flag algoritham - 3 pointer approach jisme 
// low toh zero pe hi rheta hai and high n-1 pe hi and but mid bhi zero hai kyuki woh checking element pe hai toh hum starting index maange
/*low → boundary for 0s
mid → current element we are checking (in unknown region)
high → boundary for 2s*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;
        while(mid <= high){ // kyuki unsorted ki array ki yehi range besak diagram dekhlo
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++; //zero ka number bd gaya toh pointer bhi badhna pdega
                mid++; //kyuki pheli jagah me 1 aagya wo sahi h apni jagah
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
