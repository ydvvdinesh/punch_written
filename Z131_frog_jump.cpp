//recursive solution , n index se 0 index tak jaata hai
class Solution {
public:
    int f(int n, vector<int>& heights){
        if(n == 0) return 0;
        int right = INT_MAX;
        //left and right recursion mai hume term rakhi hai , left me hum 1 index chlenege and right me hum 2 index chlenge 
        //isme saath saath energy bhi dekhni hai 
        int left = f(n-1, heights) + abs(heights[n] - heights[n-1]);
        if(n>1){
            right = f(n-2, heights) + abs(heights[n] - heights[n-2]);
        }
        return min(left, right);
    }
    
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        return f(n-1, heights);
    }
};
