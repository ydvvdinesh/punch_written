//optimal approach - same like paert 1 stack thing bas uplicate waala bnaa bna lena jo hypo thetical ho jayega, and nge orginal waalo ka btana , duplicate waalo ka help lena last waalo ke liye 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n,-1);
        for(int i = 2*n-1; i>=0;i--){ // 2n-1 is the last element of hypothetical duplicate array last element and back traversal kregi 
            // phele jitne choyte hai unhe hatoo
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            // i%n - out og aukat na jaye jo diya hai usme hi solve kre
            if(i<n){ //original waala paart hai jiska nge btana hai
                if(st.empty()){
                    nge[i] = -1;
                }
                else{
                    nge[i] = st.top(); // becoz hume small waale toh hta fiye
                }
            }
            // after assigning nge , put that i element into stack for next one 
            st.push(nums[i%n]);
        }
        return nge;
    }
};
