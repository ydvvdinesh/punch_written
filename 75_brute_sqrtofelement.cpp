class Solution {
  public:
    int floorSqrt(int n) {
          if (n == 0 || n == 1) return n; // handle 0 and 1
        int ans; // for storing the value because we are going upto max
        for (int i =1; i<n; i++){ // we play in integer not in index this time
            if(i*i <= n){
                ans = i; //jaise jaise i bdega khud maximum mil jayega
            }
            else{
                break;
            }
        }
        return ans;
    }
};
