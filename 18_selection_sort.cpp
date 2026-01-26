// 2 loop and swap ka kaam h sirf
#include<bits/stdc++.h>
using namespace std;

void selection(int arr[], int n){
    for (int i =0; i<=n-2;i++){ // usse index pe iterate krwana h jha tak hum swap lar skte hai
        int mini = i;
        for (int j = i; j <= n-1; j++){ // hume minivalue ka index chayiye isse 
            if(arr[j]<arr[mini]){ 
                mini = j;
            }
        }
        swap (arr[mini],arr[i]);
    }
      for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
};

int main (){ 
    int n;
    cin >> n; // n is the total number of element in the array
    int arr[n];
    cout << "Enter your array"<< endl;
    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    selection(arr,5);

    return 0;
}
