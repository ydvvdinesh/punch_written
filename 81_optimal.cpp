//optimal - ye aata hai 
//Range is important
// bs se hum range nikalenge and after finding the range we will apply this observation
// pura missing ka khel , find the missing no till that index = value of that index - index+1;
// ans = arr[high] + more
// more = k - missing numbers at that index
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low +high)/2; //mid is used here for again like i for the doing the things or iteration
            int missing = arr[mid]-(mid+1);
            if(missing<k){
                low = mid +1;
            }
            else{
                high = mid - 1;
            }
        }
        return high +1+k; // ye ans ko derive kiya by putting into one another
    }
};

//but tell me how bs give us range ?? - by our search space optimzation
