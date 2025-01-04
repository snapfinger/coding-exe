#include "../common_headers.h"

// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward.

// For example, 121 is a palindrome while 123 is not.
 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:

// -2^31 <= x <= 2^31 - 1
 
// Follow up: Could you solve it without converting the integer to a string?


// My sol: similar to sol 2 but less worry, but use long type
// TC: O(n)
// SC: O(1)
bool isPalindrome(int x) {
    if(x < 0) return false;
    long sum = 0;
    int y = x;
    while(y){
        sum = sum * 10 + (y % 10);
        y = y / 10;
    }

    return sum == x;
}


// Solution 2: compare sum from both directions
// Time: O(n) where n is the number of digits
// Space: O(1)
bool isPalindrome2(int x) {
    if(x < 0 || (x>0 && x%10==0)) return false;
    int sum = 0;
    while(sum < x){
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    
    if((sum == x) || (sum/10 == x)) return true;
    else return false;
}


// Solution 1: convert to string
// Time: O(n)
// Space: O(n) where n is the number of digits
 bool isPalindrome1(int x) {
    string x2 = to_string(x);
    for(int i = 0; i < x2.size(); i++){
        if(x2[i] != x2[x2.size() - i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    cout << isPalindrome2(20) << endl;
    cout << isPalindrome2(202) << endl;
}