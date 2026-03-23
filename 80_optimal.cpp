//optimal
//give capacity to this function and this will return you the day reuires to ship all packages 
int calc(vector<int>& weights, int cap){ 
        int currentday = 1; //we are on the first day
        int load = 0; // we have zero load on the ship on day 1
    for (int i = 0; i<weights.size(); i++){
        if ((load + weights[i])> cap){ // current load me kuch add karne se capacity cross hui toh package ko bolo bete kaal aoo, uss slot me tumhe rakhenge
        currentday += 1;
        load = weights[i]; //next day toh new hi assign hoga na
        }
        else{
            load += weights[i];
        }
    }
    return currentday;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int maxi = INT_MIN;
        for (int i =0; i<n; i++){
            maxi = max(maxi,weights[i]);
            sum += weights[i];
        }
        int ans = -1;
        int low = maxi;
        int high = sum;
        while (low <= high){
            int mid = (low +high)/2;
            int days_require = calc(weights,mid);
            if (days_require <= days){
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
