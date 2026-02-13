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



//FULLL CODE 
// left rotate array by one place = pura index me khelna hai
// input = [1,2,3,4,5,6,7] output = [2,3,4,5,6,7,1]
// logic = first ko last me bhejna hai and baaki elements ko shift krwana hai 
#include<bits/stdc++.h>
using namespace std;
void leftrotate(int arr[], int n){
    int temp = arr[0];
    for (int i = 1; i<n;i++){ // elements shift honge in left by one , jo aage waale index pe the ab woh piche wwale me store honge
        arr[i-1]= arr[i]; //ye line bahut important hai bhai
    }
    arr[n-1]= temp;
}
int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    leftrotate(arr,7); // ye function call sirf rotate krwayegi but print ke liye tume loop chalni hi pdegi 
    for (int i = 0 ; i<7;i++){
        cout << arr[i] << endl;
    }
    return 0;
}
