class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        pair<int,int> p;
        if(st.empty()) {
            p = {val,val};
            st.push(p);
        }
        else{
            int min = st.top().second;
            if(val<min)
                st.push(p={val,val});
            else
                st.push(p={val,min});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */