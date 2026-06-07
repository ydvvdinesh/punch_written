//brute approach -  we have to mid a minimum in stack , so we have to design a stack in that way 
/*
Approach - we wil create a pair in which ine we store the that value and the min including current value , and it will automatically giveus what we want

*/
class MinStack {
public:
    /*
    wrong stack <int> st;
    pair<int, int> pt;*/
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push({value,value});
        }
        else{
            st.push({value,min(value,st.top().second)});
        }
    }
    
    void pop() {
        st.pop(); //complete pair jayega delete hone 
    }
    
    int top() {
        return(st.top().first);
    }
    
    int getMin() {
        return st.top().second;
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
