//optimal approach - mini ka dhyan rakhna 

class MinStack {
public:
    stack<long long> st;
    long long mini = INT_MAX;
    MinStack() {
        
    }
    
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
                //yadi nayi minimu mili toh stack me modified value jayegii
                st.push(2LL *value - mini); // formula , observation
                mini = value;
            }
        }
    }
    
    void pop() {
        long long x = st.top();
        st.pop();
        if(x < mini){ // minimum ko previous me move krdo , kyuki current mini toh pop out hoga
            mini = 2*mini - x;
        }
    }
    
    int top() {
        long long x = st.top();
        if(x > mini){
            return x;
        }
        else { //iska mtalab hume modified nahi real value chayiye 
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
