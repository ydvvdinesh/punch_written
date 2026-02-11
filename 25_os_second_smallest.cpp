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
    int secondsmall = INT_MIN;
    for (int i = 0; i <n; i++){
        if (arr[i]<smallest){
            secondsmall =  smallest;
            smallest = arr[i];
        }
        else if(arr[i]<smallest && arr [i]< secondsmall){
            secondsmall = arr[i];
        }
    }
    cout << "second Smallest value in the array"<< secondsmall << endl;
    return 0;
}

// brute force - sort kro and ek loop chaloo jo ye pta lagya koi aur elemnet same toh name h aur yadi hai toh usse udr hi break kro and answer finalize kro'
