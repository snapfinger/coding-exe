#include "../common_headers.h"

// Sol 2: w/o loop
// Time complexity: O(1)
// Space complextiy: O(1)
bool isPowerOfTwo2(int n) {
    return (n > 0) && (not (n & (n - 1)));
}


// Sol 1: with loop
// Time complexity: O(log n)
// Space complexity: O(1)
bool isPowerOfTwo1(int n) {

    if(n <= 0) return false;
    while(n != 1){

        int remainder = n % 2;
        if(remainder) return false;
        n = n / 2;
    }

    return true;
}

int main(){
    cout << isPowerOfTwo1(2) << endl;
}