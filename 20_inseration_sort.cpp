// insertion sort 
#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[],int n){
    for (int i = 0; i<= n-1;i++){
       int j = i;
       while(j>0 && arr[j]<arr[j-1]){
           swap(arr[j],arr[j-1]);
           j--;
       }
    }
     for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int n;
    cout << "enter your n";
    cin >> n;
    int arr[n];
    cout <<"Enter your array";
for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    insertion_sort(arr,n);
    return 0;
}
