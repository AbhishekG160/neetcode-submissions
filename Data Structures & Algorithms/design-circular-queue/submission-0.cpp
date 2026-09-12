// class Node{
//     public:
//         int val;
//         Node* next;
//         Node():val(0), next(nullptr){};
//         Node(int v=0):val(v){};
//         Node(int v=0, Node* n):val(v), next(n){};
// };
class MyCircularQueue {
    vector<int> q;
    int head, tail;
    int size, cap;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        head = 0;
        tail = -1;
        size = 0;
        cap = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        tail = (tail+1)%cap;
        q[tail] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head = (head+1)%cap;
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[head];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */