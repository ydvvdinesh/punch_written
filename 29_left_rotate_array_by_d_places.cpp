/* left rotate the array elements by d places

Logic - same index me hi khelna hai woh most important hai 
Step-1 isme bhi same kaam krna hai jisko rotate krna h ya aage piche krna h unko temp me store kro
yadi ek element h toh temp ko varaible me use krlo and jada elements h toh temp ko array bnalo
Step-2 ab shifitng krwaoo bche huye elements by d places
step -3 last me temp waale variable ki last me daal do in left rotate 
*/
#include <bits/stdc++.h>
using namespace std;
void leftrotate(int arr[], int n, int d){ // d = number of places, n = size of the array
    d =d % n;
    // step - 1 
    int temp [d];
    for (int i = 0; i<d;i++){
// iski range 0 to d isliye hai kyuki kyuki jitne place d rotate hoga utne hi element rotate honge
// and temp ke number of elements = d places
        temp[i] = arr[i];
    }
    //step -2 
    for (int i = d; i< n; i++){
// iski range d to n-1 hogi kyuki uske phele toh piche jayenege
        arr[i-d]=arr[i]; // piche waale aage waale ko store krega , kyuki after shifitng jo right me bche woh aage aayenge 
    }
    //step - 3 
    for (int i = n-d; i<n;i++){
// ye range n-d to n-1 ho kyuki after shiting last ke kuch and limited honge jaga temp ke elemenst aayenge  
        arr[i] = temp[i-(n-d)];
    }
}
int main()
{
    int arr[7] = {1,2,3,4,5,6,7};
    leftrotate(arr,7,3); // ye function call sirf rotate krwayegi but print ke liye tume loop chalni hi pdegi 
    for (int i = 0 ; i<7;i++){
        cout << arr[i] << endl;
    }
    return 0;
}
