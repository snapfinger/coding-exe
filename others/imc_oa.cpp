#include "../common_headers.h"


int main(){
    set<vector<int>> res;
    // vector<int> cur = {1, 2, 3};
    // res.insert(cur);

    for(int a = 1; a <= 8; a++){
        for(int b = 1; b <= 8; b++){
            for(int c = 1; c <= 8; c++){
                if(a + b + c <= 10){
                    vector<int> cur = {a, b, c};
                    // cur.push_back(a);
                    // cur.push_back(b);
                    // cur.push_back(c);
                    res.insert(cur);
                }
            }
        }
    }

    for(auto val: res){
        for(auto c: val){
            cout << c << " ";
        }
        cout << endl;
    }

    cout << res.size() << endl;
}