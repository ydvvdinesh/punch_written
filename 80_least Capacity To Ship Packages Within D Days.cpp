//brute 
int calc(vector<int>& weights, int capacity){ // this function will take capcacity and return us how may day require to send all the packages 
    int current_day = 1; // we are starting day 1
    int current_load = 0; // current load exist on the ship 
    for (int i = 0; i<weights.size(); i++){
        if (current_load + weights[i]> capacity){ // “If I add this package, will I exceed the ship capacity? - if yes
        current_day = current_day +1; // move to next day for the that newest package
        current_load = weights[i]; // if yes and next day ke liye load bhi statring se hoga na
        }
        else {
            current_load += weights[i]; // if not toh aajaoo ship pe 
        }
    }
    return current_day;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum =0; 
        int maxi = INT_MIN;
        for (int i = 0; i<n; i++){
            maxi = max(maxi,weights[i]);
            sum += weights[i];
        }
        for (int i = maxi; i<=sum; i++){ // this loop is dealing into searching of capacity
            int days_required = calc(weights, i); //ki ek particular capacity pe kitne din lgenge , to deliver the packages
            if (days_required<= days){
                return i;
            }
        }
        return -1;
    }
};
//bs me bhi same hota hai wah days required toh chayiye na uske base pe hi hum capacity ko bta payenge
