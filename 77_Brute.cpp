//brute
double totaltimecal(vector<int>& arr, int rate){
    int p = arr.size();
        double totalhours = 0;
    for (int i=0; i<p; i++){
        //ceil = (arr[i] + rate - 1) / rate;
        //(a + b - 1) / b   ≡   ceil(a / b)
        totalhours = totalhours + (arr[i] + rate - 1) / rate; // indiviual time = thatpile/rate and uska maximum integer lena hai jo ceil hai
    }
    return totalhours;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int n = piles.size();
        
        int maxi = INT_MIN;
        //total time ka bhi function likhna pdega
        // loop for finding the largest value of arrray because uss tak hi calculation me variation hoga uske badd toh 0.  point me chalne lag jayega jiski ceil 1 hi hogi
        for(int i =0; i<n;i++){//this loop ended up the maximum value of the piles array
            maxi = max(maxi,piles[i]);
        } 

        for (int i = 1; i<=maxi;i++){ /// ye loop rate k , liye hai t
            double totaltime = totaltimecal(piles,i);
            if (totaltime <= h){
                 return i;   // phela mila wohi hi minimum hoga 
        }
        }
        return -1;
    }
};
