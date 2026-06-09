//optimal solution

class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
       stack<int> st;
       int n= arr.size();
       vector<int>nge(n,-1);
       for(int i =n-1; i>=0;i--){
        //remove all the elements from the stack which is smaller than the current value (i) on we are standing
        while(!st.empty() && st.top()<=arr[i]){
            st.pop(); //pop that element
        }
        //till now we removed the elemnt which is smaller than current element
        if(st.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top(); //jo bhi uss time stack me usse bda hai , aur woh top hi hoga kyuki uske phele ke saare elements delete kar diye na
        }
        //in last
        st.push(arr[i]);
       }
       return nge;
    }
};
