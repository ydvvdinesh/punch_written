//optimal approach 
//The stack is simply a waiting room.Bars stay there until they find their first smaller element on the right.
//intitution The stack in this problem acts like a waiting list of bars whose maximum rectangle cannot be determined yet. As we move from left to right, we keep pushing indices of bars into the stack while maintaining the heights in increasing order. A bar stays in the stack because we have not yet found a smaller bar on its right side. The moment we encounter a bar whose height is smaller than the height of the bar on the top of the stack, we know that the current bar is the Next Smaller Element (NSE) for the bar at the top. Therefore, that top bar's right boundary is now known, so we pop it. After popping, the new top of the stack automatically becomes its Previous Smaller Element (PSE) because the stack always maintains increasing heights. Since both boundaries are now known, we can immediately calculate the maximum width and area for that popped bar. We keep popping while the current bar is smaller than the stack's top because the same current bar may be the NSE for several taller bars. Once the top of the stack becomes smaller than the current bar (or the stack becomes empty), we stop popping and push the current bar into the stack, because it has not yet found its own smaller element on the right and must wait for a future bar. In short, the stack stores bars that are waiting for their first smaller element on the right, and whenever that smaller element appears, the bar is removed, its boundaries become known, and its rectangle area is calculated.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = 0;
        stack<int> st;
        for(int i =0; i<=n;i++){
            while(!st.empty() && (i == n ||heights[st.top()] > heights[i])){
                //yadi current waala chota hai peeche waala se toh , nse toh mil gya na current waala , kyuki wohi toh next smaller hoga na 
                int height = st.top();
                st.pop(); 
                //till now jo bda that humne usse remove kar diya so we get a new top in stack and ab automatically woh hi previous smaller hoga
                int nse = i;
                //for previous smaller ke liye stack me jayenge last tak 
                int pse = (st.empty())?-1:st.top();
                maxarea = max(maxarea, heights[height]*(nse-pse-1));

            }
            st.push(i);
        }
        return maxarea;
    }
};
