class MinStack {
    stack<int> st;
    stack<int> min_stack;

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (min_stack.empty()) {
            min_stack.push(val);
        } else {
            min_stack.push(min(min_stack.top(), val));
        }
        
    }
    
    void pop() {
        st.pop();
        min_stack.pop();
        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return min_stack.top();
        
    }
};
