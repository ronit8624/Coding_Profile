class MyQueue {
public:
    stack<int> ip;
    stack<int> op;

    MyQueue() {
    }

    void push(int x) {
        ip.push(x);
    }

    int pop() {
        if (op.empty()) {
            while (!ip.empty()) {
                op.push(ip.top());
                ip.pop();
            }
        }

        int el = op.top();
        op.pop();
        return el;
    }

    int peek() {
        if (op.empty()) {
            while (!ip.empty()) {
                op.push(ip.top());
                ip.pop();
            }
        }

        return op.top();
    }

    bool empty() {
        return ip.empty() && op.empty();
    }
};