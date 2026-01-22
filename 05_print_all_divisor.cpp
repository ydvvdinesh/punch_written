#include<bits/stdc++.h>
using namespace std;
void divi(int n){
    for (int i=1;i<=n;i++){
        if (n%i==0){
            cout <<i<<endl;
        }
    }
}
int main(){
    int entry;
    cout <<"Enter your input";
    cin>>entry;
    divi(entry);
    return 0;
}