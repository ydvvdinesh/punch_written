//optimal approch for largest array element
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout <<"Enter the size of the array";
    cin >> n;
    int arr[n];
    cout << "Enter your array number " << endl;
    for (int i = 0; i <n; i++){
        cin>> arr[i];
    }
    //logic
    int largest = arr[0];
    //checking loop 
    for (int i = 0; i <n; i++){
        if (arr[i] > largest){
            largest = arr[i];
        }
    }
    cout << "Enter the largest number" << largest << endl;
    return 0;
}

// brute force apporach - array ko sort krwaoo and last waale ko print krwado
