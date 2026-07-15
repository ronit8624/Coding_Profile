class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else if(val < mini) {
            long long newVal = 2LL * val - mini;
            st.push(newVal);
            mini = val;
        }
        else {
            st.push(val);
        }
    }

    void pop() {
        if(st.empty()) return;

        if(st.top() < mini) {
            long long val = st.top();
            mini = 2LL * mini - val;
        }

        st.pop();

        if(st.empty())
            mini = LLONG_MAX;
    }

    int top() {
        if(st.empty()) return -1;

        if(st.top() < mini)
            return mini;

        return st.top();
    }

    int getMin() {
        return mini;
    }
};