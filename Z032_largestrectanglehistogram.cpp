//bruteforce - har ek graph pe jaana and dekhna hai uski height ko use karke uske level me kitne rectangle bn skte hai 
//kab rectangle nahi bnega - yadi koi bheech me chooti height ka graph aaya toh otherwise toh bn hi jayega na 
//toh yadi hum kisi graph pe jaaye and uska next smaller and prev smaller pta lga le toh hum ye pta lag jayega ki kitne width ka rectangle bn jayega because prev smaller and next smaller ke beech me toh sab graph bade hi honge , toh wwaah toh easily graph jayega
//and yadi kisi element ke aage ya picche koi nahi toh return -1 ;
//width = nse[i]-pse[i]-1 , foemula for width 
//nse is the array which is going to the index of next smaller element of that element on which we are standing
//pse - is the array which is storing the index of previous smaller elemnt of that element on which we are stanfing
class Solution {
public:

//function to store array in which index stores the index of the next smaller element of a element onf which we are curreently standing
//why we are storing  or putting index into stack because we need index
//what we are doing in the stack we push the index and check that arr[st.top] >= arr[i] , st.top ki jagah index aayega jo store hai , yadi bda hai toh hum chota chayiye toh hum index hta te jayenge  
    vector<int> nextsmaller(vector<int> arr){
        int n = arr.size();
        stack<int>st;
        vector<int> nsse(n,-1);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                nsse[i] = n;
            }
            else{
                nsse[i] = st.top();
            }
            st.push(i);
        }
        return nsse;
    }

        vector<int> prevsmaller(vector<int> arr){
        int n = arr.size();
        stack<int>st;
        vector<int> psse(n,-1);
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                psse[i] = -1;
            }
            else{
                psse[i] = st.top();
            }
            st.push(i);
        }
        return psse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> nse = nextsmaller(heights);// we call the function
        vector <int> pse = prevsmaller(heights);
        int maxarea = INT_MIN;
        for(int i = 0; i<n ; i++){
            maxarea = max(maxarea , heights[i]*(nse[i]-pse[i]-1));
        }
        return maxarea;
    }
};
