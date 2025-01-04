#include "../common_headers.h"

class LRUCache{
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) l.erase(it->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap) {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
    
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

int main(){

    // LRUCache* obj = new LRUCache(2);
    // int param_1 = obj->get(key);
    // obj->put(key,value);
   
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    //  list<pair<int, int>> l = {{1, 1} ,{ 2, 2}};
    //   l.push_front(make_pair(key, value));
    // auto it = m.find(k1);
    l.push_front(make_pair(1, 11));
    l.push_front(make_pair(1, 12));
    m[1] = l.begin();

    auto it1 = m.find(1);

    // cout << l.rbegin()->first << endl;
     cout << it1->second->first << endl;
    // //  cout << (it1->second).size() << endl;

    // list<pair<int, int>> l = {{1, 11}, {2,12}, {3,13}};
    // l.pop_back();
    // for(auto &a: l){
    //     cout << a->first ", " << a->second << " ";
    // }
    // cout << endl;

    // int k = l.rbegin()->first;
    // cout << k << endl;
}