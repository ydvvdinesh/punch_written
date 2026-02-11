//os = ourself
#include<bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cout <<"Enter the size of the array";
    cin >> n;
    int arr[n];
    cout << "Enter your array number " << endl;
    for (int i = 0; i <n; i++){
        cin>> arr[i];
    }
    // 
    int smallest = arr[0];
    for (int i = 0; i <n; i++){
        if (arr[i]<smallest){
            smallest = arr[i];
        }
    }
    cout << "Smallest value in the array"<< smallest << endl;
    return 0;
}

// brute force - sort kro and first waale ko pakad lo
