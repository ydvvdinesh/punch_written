//number hasing - way to find the number of apperacenes using less time complexity and space complexity 

#include<bits/stdc++.h>
using namespace std;

int main (){
    int arr[5] = {1,2,5,3,2};
    
//precompution , hash index pe khelta hai , arr[i] hash ka index hai 
int hasha[6]={0};

//Loop depends on number of elements in arr, not on hash size. because we have to ierate every single element of original array
for (int i =0;i<5;i++){  // i<5 = 5 is n or total number of element // 
    hasha[arr[i]]= hasha[arr[i]] + 1;
}

 int target;
 cout << " Enter your target";
 cin >> target_numver;
 cout << hasha[target_number]; // fetch
 
return 0;
}
