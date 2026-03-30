//par space complexity 1 nahi
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
    vector<int> arr;
    int n1 = a.size();
    int n2 = b.size();
    int i =0, j=0;
    while(i<n1 && j<n2){
        if (a[i]<b[j]){
            arr.push_back(a[i]);
            i++;
        }
        else{
             arr.push_back(b[j]);
            j++;
        }
    }
    while (i<n1){
            arr.push_back(a[i]);
            i++;
    }
    while (j<n2){
        arr.push_back(a[i]);
            i++;
    }
    return arr[k-1];
  }
};
