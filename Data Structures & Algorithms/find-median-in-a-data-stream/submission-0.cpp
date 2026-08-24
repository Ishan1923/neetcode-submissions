class MedianFinder {

    priority_queue<int, vector<int>> mxheap;
    priority_queue<int, vector<int>, greater<int>> mnheap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mxheap.empty() || num < mxheap.top()) mxheap.push(num);
        else mnheap.push(num);

        if(mxheap.size() > mnheap.size() + 1){
            mnheap.push(mxheap.top());
            mxheap.pop();
        }
        else if(mnheap.size() > mxheap.size()){
            mxheap.push(mnheap.top());
            mnheap.pop();
        }

    }
    
    double findMedian() {
        return mnheap.size() == mxheap.size() ? (mnheap.top() + mxheap.top()) / 2.0 : (double)mxheap.top();
    }
};
