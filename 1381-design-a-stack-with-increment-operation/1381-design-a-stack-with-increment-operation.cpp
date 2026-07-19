class CustomStack {
private:
    vector<int> st;
    int maxSize;
    int ind;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        ind = -1;
        st.resize(maxSize);
    }
    
    void push(int x) {
        if(ind == maxSize - 1) return;
        ind++;
        st[ind] = x;
    }
    
    int pop() {
        if(ind == -1) return -1;
        int val = st[ind];
        ind--;
        return val;
    }
    
    void increment(int k, int val) {
        int limit = min(k, ind + 1);
        for(int i=0;i<limit;i++) {
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */