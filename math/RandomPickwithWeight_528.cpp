#include "../common_headers.h"


class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        for (int ind : w){
            if(s.empty())
                s.push_back(ind);
            else
                s.push_back(ind + s.back());
        }
    }

    int pickIndex() {
        int x = s.back();
        cout << "\nx: " << x << endl;
        int index = rand() % x;
        cout << "index: " << index << endl;
        auto it = upper_bound(s.begin(), s.end(), index);
        cout << "s.begin: " << *(s.begin()) << endl;
        return it - s.begin();
    }
};


int main(){
    vector<int> v1 = {1, 3, 4, 6};
    Solution s1 = Solution(v1);
    
    cout << "s1: ";
    for(auto v: s1.s){
        cout << v << " ";
    }
    cout << s1.pickIndex() << endl;
}