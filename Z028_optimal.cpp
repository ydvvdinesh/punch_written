//optimal approach - ek element me jaoo and dekho woh kitne subarray me contribute kar raha/ ya woh kitne subarray me aaraha hai left and right , and condition woh sirf unme hi contibute krega jin sub arrayo me woh sabse chota and otherwise usse chota mil gaya oh hum uske traf move krenge
//we have to find next smaller element and previous smaller element , kyuki inke beeche waalo hi ye contribute krega and smaller element right ki traf milega and previous smaller element left ki traf milega , then hum left * right = no of subaaray in which that element contribute krega and ek pen papar lo easily samaj aajayega kasie multiply hoga , after getting  no of subarray in which it contribute multiply that with that number which we are
//formula for finding lwft side = i - pse[i];
//formula for finding right side = nse[i] - i;
class Solution {
public:
//nse and pse me hum index krenge bas value ki jagah ye differnce hai nge se kyuki question me index needed

    //nse - smaller element - just reverse the sign of next greater element - optimal
    vector<int> nse(vector<int>& arr){
        int n = arr.size();
        vector<int> nsse(n);
        stack<int> st;
        for(int i =n-1;i>=0;i--){
            //remove all the greater element this time from the stacjk
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                nsse[i] = n; //Ye sirf boundary handling ke liye kiya jata hai.
            }
            else{
                nsse[i] = st.top();
            }
            st.push(i);
        }
    return nsse;
    }

//pse - left side chlega and upper waala rightside
    vector<int> pse(vector<int>& arr){
        int n = arr.size();
        vector<int> psse(n);
        stack<int> st;
        for(int i =0;i<n;i++){
            //remove all the greater element this time from the stacjk
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                psse[i] = -1; //Ye sirf boundary handling ke liye kiya jata hai.
            }
            else{
                psse[i] = st.top();
            }
            st.push(i);
        }
    return psse;
    }

//nse and pse same hai bas ek equak to ka difference hai 
//nse and pse index store krenge 

    int sumSubarrayMins(vector<int>& arr) {
        long long total = 0;
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> nextsmaller = nse(arr);
        vector<int> previoussmaller = pse(arr);
        for(int i =0; i<n;i++){
            //yaha hum index se distance nikal ke khelenge
            long long leftside = i - previoussmaller[i]; 
            long long rightside = nextsmaller[i] - i;
            long long contribution = (1LL * arr[i] * leftside % MOD) * rightside % MOD;
            // no of subarray in which contributed leftside * rightside* that number
            total = (total + contribution) % MOD;   
        }
        return (int)total;
    }
};

/*
Use a stack to find the index of the next smaller element to the right for each position
Use another stack to find the index of the previous smaller or equal element to the left for each position
For each element, determine how many subarrays it appears in as the minimum using its NSE and PSEE indices
Calculate the contribution of each element by multiplying its value with its frequency
Add each contribution to a total sum
Return the total sum modulo 10^9 + 7
*/
