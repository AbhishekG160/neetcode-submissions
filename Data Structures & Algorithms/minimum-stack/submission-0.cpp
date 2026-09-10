class MinStack {
    vector<pair<int, int>> st;
    // value , min value upto now
public:
    MinStack() {}
    void push(int val) {
        if(st.empty())  st.push_back({val, val});
        else st.push_back({val, min(val, st.back().second)});
    }
    void pop() {
        st.pop_back();   
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};
