class KthLargest {
private:
    priority_queue<int , vector<int> , greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums){
            pq.push(num);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.size() < k){
            pq.push(val);
            return pq.top();
        }
        if(val <= pq.top()) return pq.top();
        pq.pop();
        pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */