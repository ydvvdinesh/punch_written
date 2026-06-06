class MyStack {
public:
    
queue<int>q;

    MyStack() {
        
    }
    
    void push(int x) {
        //store and also check the size
        int s = q.size();
        //insert new element
        q.push(x);
        // rotate krne hai so hum majduri nahi krenge direct kaam krenge 
        for(int i = 1; i<=s; i++){
            q.push(q.front()); //copy bnaii now delete the head
            q.pop(); //top khud delete ho jayega
        } 
    }
    // in push we changed a queue permanentely
    int pop() { // stack ke results laane hai using queue
        int x =  q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};
/*
Rotated queue q inside push(). Then in pop() we are again using the same queue q. Why does that work?

Because the rotation permanently changes the order of elements inside q.
*/

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
