#include<bits/stdc++.h>
using namespace std;
bool prime_number(int n){
    int count = 0;
    for (int i = 1;i<=n;i++)
    {
        if (n%i==0){
            count= count+1;
        }
    }
    return count == 2;
}
int main (){
    int entry;
    cout << "enter your input here";
    cin >> entry;
    cout<< prime_number(entry);
    return 0;
}