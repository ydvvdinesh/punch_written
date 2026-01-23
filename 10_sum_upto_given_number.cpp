//sum upto given number a) parameterized way 
#include<bits/stdc++.h>
using namespace std;
void add(int i , int sum){
    if (i<1){
        cout << sum;
    return;
    }
    add(i-1,sum+i);
    
    int main (){
    int number;
    cout <<"Enter your value";
    cin>>number;
    add(number,0);

//b) on function call 

int add(int n){
    if (n==0) return 0;
     return n + add(n-1);
}

int main (){
    int number;
    cout <<"Enter your value";
    cin>>number;
    cout << add(number);
}

