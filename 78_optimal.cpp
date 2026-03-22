//optimal - khud bas no of boquet waala loop ke bahar aayega sirf woh dekha hai
bool possible(vector<int>& arr, int m, int k, int checking_day){
    int count = 0;
    int noofboq = 0;
    for (int i =0; i<arr.size(); i++){
        if (arr[i]<=checking_day){
            count++;
        }
        else{
            noofboq += (count/k); // by obervation/unitarymethod of class 5
            count =0;
        }
       }
    noofboq += (count/k); // 👉 Pehle pura consecutive segment count karo 
                        //👉 Phir ek baar (count/k) add karo
    if (noofboq >= m) return true;
    else{
        return false;
    }
}

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int ans = 0;
        int low = mini;
        int high = maxi;
        while (low<= high){
            int mid = (low+high)/2;
            if (possible(bloomDay,m,k,mid) == true){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
    return ans;
    }
};
