#include<bits/stdc++.h>
using namespace std;

void bubble (int arr[], int n){
    for (int i = n-1; i>=1;i--){
        for (int j = 0; j<i;j++){ 
/*j < i because after each pass, the largest element is placed at index i.
Elements from i to n-1 are already sorted, so we don't compare them again.*/
            if (arr[j]> arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
         for(int i = 0; i < n; i++){
        cout << arr[i] << " "; }
}

int main(){ 
    int n;
    cin >> n; // n is the total number of element in the array
    int arr[n];
    cout << "Enter your array"<< endl;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    bubble(arr,n);

    return 0;
}
