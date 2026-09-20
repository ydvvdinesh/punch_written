//recurison form similar to fibonaccies series , saari form mai leekhna hai 
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1){
            return 1;
        }
        // count all ways use recursion that is best 
        int left = climbStairs(n-1); // yadi ek step chala toh 1 siddhi piche chhhutttt gayi and index stairs ko denote kar raha hai toh isliye
        int right = climbStairs(n-2);
        return left + right;
    }
};
