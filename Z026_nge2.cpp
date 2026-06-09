//bruteforce - same question hai like part 1 bas isme ek cheexe ye hai ki aap left me bhi dekh skte hai .
//approach we use - (hypothetical krenge ) duplicate array concept , in which we are going to write same array again , we made it circular through using % modulo thing
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n,-1);
        // circular traversal
        for(int i =0 ; i<n;i++){
            for(int j = i+1; j<=i+n-1;j++){
                int index = j%n;
                if(nums[index]>nums[i]){
                    nge[i]=nums[index];
                    break;
                }
            }
        }
        return nge;
    }
};

/* i-n+1 reason
In a circular array of size n, for each element at index i, we need to check all other elements exactly once to find the first greater element.

Since the current element itself should not be compared again, there are only n - 1 remaining elements to examine.

We start from i + 1 and continue up to i + n - 1. This range contains exactly n - 1 positions. By using j % n, these positions wrap around the array, allowing us to simulate circular traversal.


*/
