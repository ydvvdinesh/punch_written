//optimal approach - hume ab back traverse nahi , ek pass me hi game bajna 
// ek eleemnt uthaya then uska previous greater element dhoono because yadi woh mil gaya tph current and previous ke beech toh sab current se chote honge then i-pge (index) karke consectiuve automatically mil jayegi 
class StockSpanner {
public:
    stack<pair<int,int>> st; // index,value ., index first hai and value second
    int index = -1;
    int ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        index = index +1; // it helps us to iterate 
        while(!st.empty() && st.top().second < price){ //choti hai toh htaoo , yaha value check ho rahi hai
            st.pop();
        }
        //till we delete all smller element
        int pge = (st.empty())?-1:st.top().first;
        st.push({index , price});
        ans = index - pge;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
