#include "../common_headers.h"

class TimeMap {
public:
    unordered_map<string, map<int, string>> m;
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});    
    }
    
    string get(string key, int timestamp) {
        for(auto& a: m[key]){
            cout << a.first << " " << a.second << endl;
        }
        auto itr = m[key].upper_bound(timestamp);
        return itr == m[key].begin() ? "": prev(itr)->second;
    }
};

int main(){
    TimeMap* obj = new TimeMap();
    obj->set("foo", "bar1", 2);
    obj->set("foo", "bar2", 3);
    obj->set("foo2", "bar3", 4);
    string out1 = obj->get("foo", 5);
    cout << out1 << endl;

}