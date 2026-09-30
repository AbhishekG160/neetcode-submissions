class MedianFinder {
    priority_queue<int> maxh; // smaller half (n/2 elems or one more)
    priority_queue<int, vector<int>, greater<int>> minh; // larger half (n/2 elems)
public:
    MedianFinder() {}
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        while(maxh.size() < minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size() == minh.size())
            return (maxh.top()+minh.top())/2.0;
        else return maxh.top();
    }
};
