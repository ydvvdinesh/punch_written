#include<bits/stdc++.h>
using namespace std;
void f(int i,int n){
    if (i>n) return ;
    cout<<i<<endl;
    f(i+1,n);
}

int main(){
    int start;
    int end;
    cin>>start>>end;
    cout << "print all values";
    f(start,end);
    return 0;
}