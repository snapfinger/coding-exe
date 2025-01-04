#include "../common_headers.h"

class MyQueue {
     stack<int> in, out;
public:

   void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int val = peek();
        cout << out.top() << endl;
        out.pop();
        return val;
    }
    
    int peek() {
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};

int main(){
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->pop();
    obj->pop();
    obj->pop();
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */