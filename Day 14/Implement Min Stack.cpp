class MinStack {
    stack<long> s;
    long mini = LONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.size() == 0) {
            mini = val;
            s.push(val);
            return;
        }
        if(val >= mini){
            s.push(val);
        }else{
            s.push(2*1l*val - mini);
            mini = val;
        }
    }
    
    void pop() {
        if(mini <= s.top()){
            s.pop();
        }
        else{
            mini = 2*1l*mini - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(mini <= s.top()){
            return s.top();
        }
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */