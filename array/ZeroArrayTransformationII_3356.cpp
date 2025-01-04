#include "../common_headers.h"

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), sum = 0, k = 0;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cout << "i: " << i << endl;
        while (sum + cnt[i] < nums[i]) {
            cout << " sum + cnt[i]: " << sum + cnt[i] << ", nums[i]: " << nums[i] << endl;
            if (k == queries.size()) return -1;
            int l = queries[k][0];
            int r = queries[k][1];
            int val = queries[k][2]; 
            k++;
            
            if (r < i) continue;
            cnt[max(l, i)] += val;
            cnt[r + 1] -= val;
        }
        sum += cnt[i];
    }
    return k;
}


int main(){
    vector<int> nums1 = {2,0,2};
    vector<vector<int>> queries1 = {{0,2,1}, {0,2,1}, {1,1,3}};
    minZeroArray(nums1, queries1);

}