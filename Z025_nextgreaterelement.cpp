class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        vector <int> nge(n,-1);
       for(int i = 0; i<n;i++){
        for(int j = i+1; j<n; j++){
            if(arr[j]>arr[i]){
                nge[i] = arr[j];
                break;
            }
        }
       }
       return nge;
    }
};
// leetcode pe thodi statement alag hai
