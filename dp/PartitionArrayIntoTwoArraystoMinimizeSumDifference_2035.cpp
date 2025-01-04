#include "../common_headers.h"


// TC: O(2^n * n)
int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int N = n/2;
    vector<vector<int>> left(N+1), right(N+1);
    
    // create the map (implemented in vector<vector>) for search 
    // in terms of size later
    for(int mask=0; mask<(1<<N); mask++){
        int sz = 0, l = 0, r = 0;
        for(int i = 0; i < N; i++){
            if(mask & (1<<i)){
                sz++;
                l += nums[i];
                r += nums[N + i];
            }
        }
        
        left[sz].push_back(l);
        right[sz].push_back(r);
    }
    
    for(int sz=0; sz<N; sz++){
        sort(right[sz].begin(), right[sz].end());
    }
    
    int res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));
    
    for(int sz=1; sz<N; sz++){
        for(auto left_sum: left[sz]){
            int rsz = N - sz;
            int target = sum / 2 - left_sum;
            auto &a = right[rsz];
            auto itr = lower_bound(a.begin(), a.end(), target);

            if(itr != a.end()){
                res = min(res, abs(sum-2*(left_sum+(*itr))));
            }else if(itr != a.begin()){
                itr = prev(itr);
                res = min(res, abs(sum-2*(left_sum+(*itr))));
            }
        }
    }
    
    return res;
    
}

int main(){
    vector<int> n1 = {3, 9, 7, 3};
    cout << minimumDifference(n1) << endl;
}