#include "../common_headers.h"


// with one stack
class MyStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size() - 1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int front_val = q.front();
        q.pop();
        return front_val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */