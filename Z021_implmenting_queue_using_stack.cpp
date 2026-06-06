//STack kause krke queue ke answer dene hai - approach 1
class MyQueue {
public:

    stack<int> s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        /*
        1.s1 -> s2 - sends all from s1 to s2 (in reverse order = obvious hai )
        2. x -> s1
        3.s2->s1 sends from s2 to s1 and we will get result
        */
        while(s1.size() !=0){
            s2.push(s1.top()); // humne push kiye s1.top into s1
            s1.pop();
        }
        s1.push(x);
        while(s2.size() != 0){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
//s1 is our main take jo answer dega same to same as queue

    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
