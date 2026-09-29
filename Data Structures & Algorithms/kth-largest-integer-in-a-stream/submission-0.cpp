class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minh;
    int cap;
public:
    KthLargest(int k, vector<int>& nums):cap(k) {
        for(int n:nums){
            minh.push(n);
            if(minh.size() > cap)
                minh.pop();
        }
    }
    
    int add(int val) {
        minh.push(val);
            if(minh.size() > cap)
                minh.pop();
        return minh.top();
    }
};
