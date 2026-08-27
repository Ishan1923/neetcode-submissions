class MinStack {

    stack<int> st;
    stack<int> st2;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (st2.empty() || st2.top() >= val){
            st2.push(val);
        }
        else if (st2.top() < val){
            st2.push(st2.top());
        }
    }
    
    void pop() {
        st.pop();
        st2.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
