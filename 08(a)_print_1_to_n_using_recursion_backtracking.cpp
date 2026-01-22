//print 1 to given number n by backtracking
#include<bits/stdc++.h>
using namespace std;
void f(int i,int n){
    if (i<n) return ; //here n is 1 because we are going 1 to n 
    f (i-1,n);
    cout<<i<<endl;
}
int main(){
    int start, end;
    cin >> start >> end;
    f(start, end);
    return 0;
}

// i game chlta h , n toh stable waala kaam krta hai 