//optimal approach - phele iterative ja rahe hai later isko change kar denge recurisve me but concept same hoga 
//basic idea - base ko badhte jate jayenge and power ko ghata te 
//if yadi power odd hai toh power ko n/2 krenge and base ki power ko square jisse dono increase ho jayenge 
//if power odd hai toh ek base ki power ko answer me multiply krwa denge jisse woh even hi bach jayegi then agle iteration me usme operation kar denge 
//hum isko even zone mai le jaake solve krenge, par jaise hi odd mileg usko alag krenge woh value satrting waah ki hogi aise hissab kitab chlega
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n; // to prevent the overflow 
        // condition yadi -negative power aayi toh
        if(N<0){
          x = 1/x;
          N = -N;
        }
        if(N == 0){
          return 1;
        }
        // lets break the power by n-1 or n/2
        while(N>0){
          //odd
          if(N%2 == 1){
            ans = ans*x;
            N = N-1;
          }
          //even
          if(N%2 == 0){
            x = x*x;
            N = N/2;
          }
        }
        return ans;
    }
};
