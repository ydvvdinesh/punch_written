// optimal approach - we have to reduce the space complexity so simple pass me cheeze bhejenge
class MinStack {
public:
    stack<int> st;
    int mini = INT_MAX;
    MinStack() {
        
    }
    //isme minimum har step ka track chayiye  and modified value ka bhi ghyan rakhna pdega
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mini = value;
        }
        else{
            if(value > mini){
                st.push(value);
            }
            else{
                //push modified value into stack
                st.push(2*value - mini); // mini store krga so obvious last waala hi dega
                mini = value;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        else{
        int x = st.top();
        st.pop();

        if(x < mini) {
            mini = 2 * mini - x; // previous minimum pe chla jayega ,  kyuki first minimum pop out hoga 
         }
        }
    }
    
    int top() {
            int x = st.top();
            if(x > mini){
                return x;
            }
            else{
                return mini;
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
