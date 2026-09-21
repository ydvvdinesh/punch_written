//now Convert to recursive 
// operation iterative ke hi hai but unko hi recurive medaal rahe hai 
class Solution {
public:
    double myPow(double x, int n) { // this function gives the value of x^n
        long long m = n;
        if(m<0){
          x = 1/x;
          m = -m;
        }

        if(m == 0){ // ye base case hoga iske baad power neeche nahi jayegi, isme jo answer aaye woh return kar dena
          return 1;
        }
        //if odd hai toh power ghtege gi and base as ek value side multiply ho jayega 
        if(m%2 == 1){
          return x*myPow(x, m-1);// this function gives the value of x^n-, aise aise karte hum bade segment to chota krenge n to 0 jayenge and return mai neeche se answer leke aayenge 
          // ye hi answer dega 
        }
        //else even hi hoiga so condition ki koi zarroort nahi hai and base square hoga 
        return myPow(x*x, m/2);
    }
};
