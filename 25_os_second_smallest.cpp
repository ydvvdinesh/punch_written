#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter your array numbers:" << endl;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int smallest = INT_MAX;
    int secondsmall = INT_MAX;

    for(int i = 0; i < n; i++){
        if(arr[i] < smallest){
            secondsmall = smallest;
            smallest = arr[i];
        }
        else if(arr[i] > smallest && arr[i] < secondsmall){
            secondsmall = arr[i];
        }
    }

    cout << "Second smallest value in the array: " << secondsmall << endl;

    return 0;
}
