//brute force smaja nahi aayi raat lena 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.nums();
        for(int i =0; i<n;i++){
            if (arr[i]<k){
                k++;
            }
            else{
                return i;
                break;
            }    
        }
        return -1;
    }
};
