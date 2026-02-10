#include<bits/stdc++.h>
using namespace std;
int main (){
    int n; // without size you can`t declare an array that`s why we write n in upper line
    int marks[n]; // here we declare array named marks with size n 
    cout << "Enter size of the array";
    cin >> n ; 
    for (int i =0 ; i <n ; i++){ // array indexing 0 se start hoti h / loop me toh hum kaise bhi khel skte hai  
        cin >> marks[i];
    }
    cout << " Number at index 3 "<< marks[3];
    return 0;
}
