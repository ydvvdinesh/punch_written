#include<bits/stdc++.h>
using namespace std;
int main (){
    string s;
    cout<<"Enter your string : ";
    cin>>s;
    //precomputation
    // for lowercase
    int hash[26]={0};
    for(int i = 0; i <s.size();i++){
        hash[s[i]-'a'] = hash[s[i]-'a'] + 1;
    }
    // fetch 
    char target;
    cout << "tell me which charcter : ";
    cin>>target;
    cout << hash[target - 'a'];
    return 0;
}
