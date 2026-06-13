//brute approach - sum of all seperrate subarray (largest of that subarray - smallest of that subarray)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        //generate all subarray 
        for(int i =0; i<n; i++){
            int largest = nums[i];
            int smallest = nums[i];
            // why i+1 ? isse toh ek subaaray rhe jayga indiviual waala ,
            //yes, rehejayega because hume uski need bhi nahi hai na  bez largest - smallest nikalna  so khud ka khud subtraction -ve me hi jayega 
            for (int j = i+1; j<n; j++){
                largest = max(largest, nums[j]); // it find maximum of that array
                smallest = min(smallest, nums[j]);
                sum = sum + (largest-smallest);
            }
        }
        return sum;
    }
};
