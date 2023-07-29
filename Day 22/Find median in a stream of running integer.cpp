class MedianFinder {
private:
    priority_queue<int> left;
    priority_queue<int , vector<int> , greater<int>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(right.size() == 0){
            right.push(num);
            return;
        }
        if(num < right.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }

        while(!right.empty() && right.size() > left.size() + 1){
            int val = right.top();
            left.push(val);
            right.pop();
        }

        while(!left.empty() && left.size() > right.size()){
            int val = left.top();
            right.push(val);
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() != right.size()){
            return right.top();
        }
        return (left.top() + right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */