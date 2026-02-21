class Solution {
public:
    void maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        // starting index of current subarray
        int start = 0; 
        
        // indices of the maximum sum subarray
        int ansStart = -1, ansEnd = -1; 

        for (int i =0; i<n; i++){
            if (sum ==0){ // jab bhi sum zero hoga hum next element se start krenge, index next element hi hoga
                start= i;
            }
            sum = sum+ nums[i];
            if (sum>maxi){
                maxi = sum;
                ansStart = start; // jaise hi maxi piche sum se jaada hooga mtlb ye hi sub array lena hai
                ansEnd = i; // end jaha tak ye  sub array iterate kre
            }
            if (sum < 0){
                sum =0;
            }
        }

        cout << "Maximum Subarray: ";
        for (int i = ansStart; i <= ansEnd; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;

        cout << "Maximum Sum = " << maxi << endl;
    }
};
