class MinStack {
private:
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int value) {
        if(st.empty()) {
            mini = value;
            st.push(value);
        }
        else if(value < mini) {
            st.push(2LL * value - mini);
            mini = value;
        }
        else {
            st.push(value);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top() < mini) {
            long long val = st.top();
            mini = 2 * mini - val;
        }

        st.pop();

        if(st.empty()) {
            mini = LLONG_MAX;
        }
    }
    
    int top() {
        if(st.empty())
            return -1;

        if(st.top() < mini) 
            return mini;

        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */