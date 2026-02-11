// second largest - optimal approach 
//phele largest nikalo then and largest ke piche waale ko pakdo jisko largest ne replace kiya hai
#include<bits/stdc++.h>
using namespace std;
int main (){
    int n;
    cout <<"Enter the size of the array";
    cin >> n;
    int arr[n];
    cout << "Enter your array number " << endl;
    for (int i = 0; i <n; i++){
        cin>> arr[i];
    }
    
    // real code
    int largest = arr[0];
    int secondlarge = INT_MIN;
    for (int i = 0; i <n; i++){
        if (arr[i]>largest){
            secondlarge= largest; // replacing chl rahi h dono ki, purane waale ko naye me dal rhae hai 
            largest = arr[i];
        }
        else if (arr[i]<largest && arr[i]>secondlarge){ // yadi koi do same ho ya ya koi akela na mil jaye 
            secondlarge = arr[i];
        }
    }
    cout << "second largest number " << secondlarge << endl;
    
    
    return 0;
}
