//logic
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int temp = arr[0]; // ye kaam aate hai roatation 
     for (int i = 1; i<arr.size(); i++){ // ye loop kaam aati hai shifiting me
           arr[i-1]=arr[i]; // arr[i] ke index ki value arr ke index i-1 pe daal do
        }
     arr[arr.size()-1] = temp; // ye kaam aate hai roatation
    }
};
