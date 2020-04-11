#include <bits/stdc++.h>

class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int> s;
    std::stack<int> min;
    int size;
    
    MinStack() {
        size = 0;    
    }
    
    void push(int x) {
        s.push(x);
        if(min.empty())
            min.push(x);
        else if(min.top() >= x)
            min.push(x);
        size++;
    }
    
    void pop() {
        if(s.empty())
            return;
        if(min.top() == s.top())
            min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */