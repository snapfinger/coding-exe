#include "../common_headers.h"

class MyHashMap {
    vector<int> vec_;
public:
    MyHashMap() {
        vec_.resize(1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        vec_[key] = value;
    }
    
    int get(int key) {
       return vec_[key];
    }
    
    void remove(int key) {
        vec_[key] = -1;
    }
};

void printAll(MyHashMap* obj){
    for(auto p: obj->vec_){
        cout << p.first << " " << p.second << endl;
    }
}

int main(){
    MyHashMap* obj = new MyHashMap();
    obj->put(1, 1);
    obj->put(2, 2);
    // printAll(obj);
    obj->put(2, 1);
    obj->remove(2);
    // cout << "here" << endl;
//     printAll(obj);
//     cout << "here2" << endl;
//     cout << obj->get(2) << endl;
}
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */