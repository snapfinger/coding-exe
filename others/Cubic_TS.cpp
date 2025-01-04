#include "../common_headers.h"

// Two sigma
// Given N, find all pairs of (a, b) s.t. a^3 + b^3 = N.

vector<vector<int>> findCubPair(int N){
    vector<vector<int>> rst;
    
    for(int a = 1; a <= cbrt(N); a++){
        int b = N - pow(a, 3);
        int b_cbrt = cbrt(b);

        if(pow(b_cbrt, 3) + pow(a, 3) == N){
            vector<int> cur_rst = {a, b_cbrt};
            rst.push_back(cur_rst);
        }
    }

    return rst;

}

int main(){
    for(int x=1; x <= 10; x++){

        cout << "x: " << x << endl;

        vector<vector<int>> rst1 = findCubPair(x);

        for(int i=0; i<rst1.size(); i++){
            for(auto v: rst1[i]){
                cout << v << " ";
            }
            cout << endl;
        }
    }
    
}