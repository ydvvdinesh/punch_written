//optimal apporach , total time of eating all bananas will be in given limit, toh tell the minimum rate jiss se khaye woh
//wrong answer ciel direct likhne se aaya yhe uske jagah uski ki trick kaam kro but ceil only works on floating point not on integer divison
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
        int ans = INT_MAX;
        int low = 1; // search space , jo rate hoga minimum toh wo one hoga and maximum last value tak hoga
        int high = maxi;
        while(low<=high){
            int mid = (low +((high-low)/2));
           double totaltime = totaltimecal(piles,mid);
            if (totaltime <= h){
                ans = mid;
                high = mid-1; // kyuki minimum doondna hai , toh obvious h left side jayenge
            }
            else{
                low = mid+1;
            }
        }
    return ans;
    }
};
