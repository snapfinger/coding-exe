#include "../common_headers.h"


void printmap(unordered_map<int, int> count){
    cout << " count map: " << endl;
    for(auto ele: count){
        cout << "  " << ele.first << ": " << ele.second << endl;
    }
}


// sol: sliding window
// TC: O(nlogn)
// SC: O(n)
int maxFrequency(vector<int>& nums, int k, int numOperations){
    sort(nums.begin(), nums.end());
    int n = nums.size();
    unordered_map<int, int> count;
    int i = 0, j = 0, rst = 0;
    for(auto num: nums){
        cout << "---- num: " << num << "-------" << endl;
        while(j < n && nums[j] <= num + k){
            count[nums[j]]++;
            j++;

            cout << " j: " << j << endl;
            printmap(count);
        }
        
        while(i < n && nums[i] < num - k){
            count[nums[i]]--;
            i++;
            cout << " i: " << i << endl;
            printmap(count);
        }
        
        int cur_len = min(j - i, count[num] + numOperations);
        cout << " cur_len= " << cur_len << " | j - i: " << j - i << " | count[num] + numOperations: " << count[num] + numOperations << endl;
        rst = max(rst, cur_len);
        cout << "rst: " << rst << endl;
    }
    
    for(int i = 0, j = 0; j < n; j++){
        while(nums[i] < nums[j] - 2 * k){
            i++;
        }
        
        rst = max(rst, min (j - i + 1, numOperations));
    }
    return rst;

}


int main(){
    vector<int> nums1 = {1, 4, 5};
    int k1 = 1;
    int numOp = 2;
    maxFrequency(nums1, k1, numOp);
}