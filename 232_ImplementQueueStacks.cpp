#include <stack>

class MyQueue {
    std::stack<int> input_st;
    std::stack<int> output_st;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input_st.push(x);
    }

    // only work with output stack
    int pop() {
        peek();
        int v = output_st.top();
        output_st.pop();
        return v;
    }
    
    int peek() {
        if (output_st.empty()) {
            // all new elems are in input stack in reversed popping order
            while (!input_st.empty()) {
                output_st.push(input_st.top());
                input_st.pop();
            }
        }
        return output_st.top();
    }
    
    bool empty() {
        return input_st.empty() && output_st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
*/

// Runtime: O(1) amortised for peek(), pop()
// Memory: O(n)
