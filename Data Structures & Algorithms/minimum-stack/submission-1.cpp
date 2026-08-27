class MinStack {
public:


    std::stack<int> st;
    std::stack<int> mins;


    MinStack() {
        
    }
    
    void push(int val) {

        if(st.empty())
        {
            mins.push(val);
            st.push(val);

            return;
        }
        
        st.push(val);
        if(val<=mins.top())
        {
            mins.push(val);
        }
        
    }
    
    void pop() {

        if(st.top() == mins.top())
        {
            st.pop();
            mins.pop();
            return;
        }
        
        st.pop();




        
    }
    
    int top() {

        return st.top();
        
    }
    
    int getMin() {

        return mins.top();
        

        // return min
        
    }
};
