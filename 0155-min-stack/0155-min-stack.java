class MinStack {
    Stack<Long> st;
    long mini;

    public MinStack() {
        st = new Stack<>();
        mini = Long.MAX_VALUE;
    }
    
    public void push(int value) {
        if(st.isEmpty()) {
            st.push((long)value);
            mini = value;
        }
        else if(value < mini) {
            long newVal = (2L * value) - mini;
            st.push(newVal);
            mini = value;
        }
        else {
            st.push((long)value);
        }
    }
    
    public void pop() {
        if(st.isEmpty()) return;

        if(st.peek() < mini) {
            long newVal = st.peek();
            mini = (2 * mini) - newVal;
        }

        st.pop();

        if(st.isEmpty()) {
            mini = Long.MAX_VALUE;
        }
    }
    
    public int top() {
        if(st.empty()) return -1;

        if(st.peek() < mini) {
            return (int) mini;
        }

        return st.peek().intValue();
    }
    
    public int getMin() {
        return (int)mini;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(value);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */