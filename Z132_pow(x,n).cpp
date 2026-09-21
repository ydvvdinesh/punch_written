//brute force - we have to calculate , x ki power n , where x is the base and n is the power 
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n; //what if n is the int_min so thats why we are using it 
        //long long can easily store this value because when it turns to negative later jab postive bnegi toh woh maximum ki int condititon ko by pass kar skati hai , matalb positive int ki value range cross kardi 
        // used to store the answer
        //what if we got a negative power, so we convert that into a proper positive value, by putting the value in denominator
        if(N<0){
          x = 1/x; 
          N = -N;
        }
        //n times multiply karna hai 
        for(int i = 1; i<=N; i++){
          ans = ans*x;
        }
        return ans;
    }
};
