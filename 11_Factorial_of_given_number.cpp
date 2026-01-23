#include<bits/stdc++.h>
using namespace std;
int f(int n){
    if (n==0) return 1;/*return can be used inside any control statement (if, else, loops) 
    as long as it is inside a function,
    and it terminates the entire function execution immediately.*/
    return n* f(n-1);
}               
int main (){
    int entry;
    cin >> entry;
    cout<< "Factorial of given number " << f(entry); 
    // jab bhi int function return de toh woh cout se print krwana pdega 
    return 0;
}
