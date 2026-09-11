class FreqStack {
    unordered_map<int, int> counter;
    // val, count
    unordered_map<int, stack<int>> stacks;
    // count, stack of values
    int maxcount;
public:
    FreqStack():maxcount(0) {}
    
    void push(int val) {
        int count = 1 + counter[val];
        counter[val]++;
        if(maxcount < count){
            maxcount = count;
        }
        stacks[count].push(val);
    }
    
    int pop() {
        int val = stacks[maxcount].top();
        stacks[maxcount].pop();
        counter[val]--;
        if(stacks[maxcount].empty()){
            maxcount--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */