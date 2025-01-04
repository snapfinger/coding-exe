class LRUCache {
    int cap_;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
    
public:
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        auto iter = m.find(key);
        if(iter == m.end()) return -1;
        l.splice(l.begin(), l, iter->second);
        return iter->second->second;
    }
    
    void put(int key, int value) {
        auto iter = m.find(key);
        
        if(iter != m.end()) l.erase(iter->second);
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        
        
        // if(iter != m.end()) l.erase(iter->second);
        // l.push_front(make_pair(key, value));
        // m[key] = l.begin();
        
        if(m.size() > cap_){
            int k = l.rbegin() -> first;
            // int k = l.back().first; also works
            m.erase(k);
            l.pop_back();
        }
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */