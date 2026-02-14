// linear search - easy
//logic - 1. iterate krwaoo and jaha pheli occurence mile wo index return krde
#include<bits/stdc++.h>
using namespace std;
int linearSearch(int nums [],int n, int target) {
        for (int i = 0; i<n; i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    cout <<"index of the number 3 - "<<linearSearch(arr,7,7);
    return 0;
}
