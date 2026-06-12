// saare subarray generate kro and har sub array kla minimum vlaue ka element nikalo and unko add karte chalo
//minimum nikalo har subarray ka unko add kardo
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total = 0; // store the total sum after finding the minimum value of every subarraty
        const int MOD = 1e9 + 7;
        for(int i =0; i<n; i++){
            int mini = arr[i];//that will assgin single sabarray as first minimum for new sub array
            for(int j = i; j<n; j++){
                mini = min(mini,arr[j]); //minimum of that subarray
                total = (total + mini) % MOD;
            }
        }
        return (int)total;
    }
};
