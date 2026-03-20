class Solution {
  public:
    int floorSqrt(int n) {
        int ans;
        if (n ==0 || n==1) return n;
        int low = 1; 
        int high = n; // we are going to play in integer not in number
        while(low<=high){
            int mid = (low +(high-low)/2);
            long long val = mid*mid;
            if (val<=n){
                ans = mid;
                //if possible toh maximum ki khoj me right me jayenge by eleminating the left
                low = mid +1;
            }
            else{
                high = mid -1; //kyuki jo high usse right me jayegenfe toh sab badi value hi milegi
                // final searched thig toh equal waale se milegi
            }
        }
        return ans;
    }
};
