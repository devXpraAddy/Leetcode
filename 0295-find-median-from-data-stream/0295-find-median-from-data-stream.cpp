class MedianFinder {
public:
    priority_queue<int> left_pq;
    priority_queue<int, vector<int>, greater<int>> right_pq;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_pq.empty() || num < left_pq.top()){
            left_pq.push(num);
        }else{
            right_pq.push(num);
        }
        if(abs((int)left_pq.size() - (int)right_pq.size()) > 1){
            right_pq.push(left_pq.top());
            left_pq.pop();
        }else if(left_pq.size() < right_pq.size()){
            left_pq.push(right_pq.top());
            right_pq.pop();
        }
    }
    
    double findMedian() {
        if(left_pq.size() == right_pq.size()){
            return (double)(left_pq.top() + right_pq.top())/2;
        }
        return left_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */ 