// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
 

// Constraints:
// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104

#include "../common_headers.h"

// Kadane's algorithm
// to find a contiguous subarray giving max profit
// TC: O(n)
// SC: O(1)
int maxProfit(vector<int>& prices) {
    int rst = 0, cur_rst = 0;
    for(int i = 0; i < prices.size() - 1; i++){
        if(cur_rst + prices[i+1] - prices[i] < 0){
            cur_rst = 0;
        }else{
            cur_rst += prices[i+1] - prices[i];
            rst = max(rst, cur_rst);
        }
    }
    
    return rst;
}

// variant: if the given values are differences
int myMaxProfit(vector<int>& diffs){
    int cur_max = 0, all_max = 0;
    for(int i=0; i<diffs.size();i++){
        cur_max = max(0, cur_max+diffs[i]);
        all_max = max(all_max, cur_max);
    }
    return all_max;
}


int main(){
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    vector<int> diff1 = {-6, 4, -2, 3, -2};
    cout << maxProfit(prices1) << endl;
    cout << myMaxProfit(diff1) << endl;

    cout << endl;
    vector<int> prices2 = {7, 6, 4, 3, 1};
    vector<int> diff2 = {-1, -2, -1, -2};
    cout << maxProfit(prices2) << endl;
    cout << myMaxProfit(diff2) << endl;
}