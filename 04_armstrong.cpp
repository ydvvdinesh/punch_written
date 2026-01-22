#include<bits/stdc++.h>
using namespace std; 
bool armstrong(int n){
    int dup = n;
    int sum = 0;
    while (n>0){
        int ld = n%10;
        sum= sum + ld*ld*ld;
        n=n/10;
    }
    return sum == dup;
}

int main(){
    int entry;
    cout << "Enter your input ";
    cin>>entry;
    cout << armstrong(entry);
    return 0;
}