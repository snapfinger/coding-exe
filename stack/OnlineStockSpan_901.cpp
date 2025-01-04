#include "../common_headers.h"


// TC: 
// amortized TC one next() call: O(1)
// for n calls: O(n)

// SC:
// O(n) for n calls for next()
class StockSpanner {
    private:
        stack<pair<int, int>> st;
        
    public:
        StockSpanner() {}
        
        int next(int price) {
            int cnt = 1;
            while(!st.empty() && (st.top().first <= price)){
                auto cur = st.top();
                cnt += cur.second;
                st.pop();
            }
            st.push({price, cnt});
            return cnt;
        }
};
