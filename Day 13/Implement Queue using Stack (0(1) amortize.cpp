class MyQueue {
    stack<int> input , output;
    // stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty() == false){
            int temp = output.top();
            output.pop();
            return temp;
        }
        else{
            while(input.empty() != true){
                int t = input.top();
                input.pop();
                output.push(t);
            }
            
            int temp =  output.top();
            output.pop();
            return temp;
        }
    }
    
    int peek() {
        if(output.empty() == false){
            // int temp = output.top();
            
            return output.top();
        }
        else{
            while(input.empty() != true){
                int t = input.top();
                input.pop();
                output.push(t);
            }
            return output.top();
        }
    }
    
    bool empty() {
        return input.empty() && output.empty();
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