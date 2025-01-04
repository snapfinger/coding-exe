#include "../common_headers.h"
 
 void printVec(vector<int>& vec){
     for(auto v: vec){
          cout << v << " ";
     }
     cout << endl;
}

// DP
// TC: O(nk)
// SC: O(n)
int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if(k >= len/2){
        int sum = 0;
        for(int i=0; i<prices.size()-1; i++){
            sum += max(0, prices[i+1] - prices[i]);
        }
        return sum;
    }
            
    vector<int> b(k+1,INT_MIN);
    vector<int> s(k+1,0);
    for(auto p : prices) {
        cout << "p: " << p << endl;
        for(int i=1; i<=k; i++) {
            b[i] = max(b[i], s[i-1]-p);
            s[i] = max(s[i], b[i]+p);
        }

        // printVec(b);
        //  printVec(s);

    }
    return s[k];
}


int main(){
    vector<int> v1 = {2, 4, 1, 3, 5};
    int k1 = 2;
    maxProfit(k1, v1);

}