/*
 * Leetcode: 155. 最小栈
 * tag: stack
 * language: C++
 * data: 2020/5/13
 */

//核心思路是当值入栈时，若比当前最小值小，则将当前最小值先入栈
//pop操作时遇到最小值出栈，再取出当前最小值

class MinStack {
private:
    stack<int> s;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (s.empty() || x <= min) {
            s.push(min);
            min = x;
        } 
        s.push(x);
    }
    
    void pop() {
        if (s.top() == min) {
            s.pop();
            min = s.top();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
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