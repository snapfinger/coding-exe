#include "../common_headers.h"


// sol 2: recursion
// TC: O(n / 2)
double myPow0(double x, int n) {
    double rst = 1.0;
    if(n == 0) return 1.0;
    else if(n < 0){
        return 1/x * myPow(1/x, -(n+1));
    }
    
    return n % 2 == 0? myPow(x*x, n/2): x * myPow(x*x, n/2);
}


// sol 1: iterative