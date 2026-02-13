// logic step-1 , phele jitne place bole h utne place ko reverse kro then bche huye element ko reverse kro then jab whole reversed array mil jaye to usko reverse krdo
/*
arr → start of array (index 0)

arr+d → start from index d

arr+n → end of array (one past last element)

arr      = address of arr[0]
arr + 1  = address of arr[1]
arr + 2  = address of arr[2]
arr + 3  = address of arr[3]
arr + 4  = address of arr[4] 
arr + 5  = address after last element  if n=5 

*/
#include<bits/stdc++.h>
using namespace std; 
void leftrotate(int arr [] , int n ,int d){
    reverse(arr,arr + d);
    reverse(arr + d, arr+n);
    reverse(arr, arr+n);
}
int main (){
    int arr[7] = {1,2,3,4,5,6,7};
    leftrotate(arr,7,3); // ye function call sirf rotate krwayegi but print ke liye tume loop chalni hi pdegi 
    for (int i = 0 ; i<7;i++){
        cout << arr[i] << endl;
    }
    return 0;
}
