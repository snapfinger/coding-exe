#include "../common_headers.h"

class MovingAverage {
    private:
        queue<int> q;
        double sum;
        int size;
public:
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        if(q.size() >= size){
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */