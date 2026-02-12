//logic
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int temp = arr[0];
     for (int i = 1; i<arr.size(); i++){
           arr[i-1]=arr[i]; // arr[i] ke index ki value arr ke index i-1 pe daal do
        }
     arr[arr.size()-1] = temp;
    }
};
