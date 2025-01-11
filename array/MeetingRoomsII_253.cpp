#include "../common_headers.h"

// method 3-1: one 2D vector 
// to be consistent with LC 2054
// TC: O(n logn)
// SC: O(n)
// n: #intervals
int minMeetingRooms3_1(vector<vector<int>>& intervals) {
        vector<vector<int>> recs;
        for(auto interval: intervals){
            int start = interval[0];
            int end = interval[1];
            recs.push_back({start, 1});
            recs.push_back({end, 0});
        }

        sort(recs.begin(), recs.end());

        int rst = 0, cur_rst = 0;

        for(auto rec: recs){
            if(rec[1] == 1){
                cur_rst += 1;
            }else{
                cur_rst -= 1;
            }

            rst = max(rst, cur_rst);

        }

        return rst;

    }


// method 3-2: 2 vectors
int minMeetingRooms3_2(vector<vector<int>>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for(auto a: intervals){
            starts.push_back(a[0]);
            ends.push_back(a[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int cnt = 0, end_idx = 0;
        for(int i = 0; i < intervals.size(); i++){
            if(starts[i] < ends[end_idx]) cnt += 1;
            else end_idx++;
        }
        
        return cnt;
    }


// method 2: one map
// TC: O(nlogn)
int minMeetingRooms2(vector<vector<int>>& intervals) {
    
    map<int, int> m;
    for(auto interval: intervals){
        m[interval[0]]++;
        m[interval[1]]--;
    }
    
    int cnt = 0, cur_cnt = 0;
    
    for(auto v: m){
        cur_cnt += v.second;
        cnt = max(cnt, cur_cnt);
    }
    
    return cnt;
}


// method 3: 1 priority queue
// TC: O(nlogn)
// SC: O(n)
int minMeetingRooms1(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto a: intervals){
        if(!pq.empty() && (a[0] >= pq.top())) pq.pop();
        pq.push(a[1]);
    }
    
    return pq.size();
}


int main(){
    vector<vector<int>> intervals1 = {{0,30}, {5,10},{15,20}};
    cout << minMeetingRooms1(intervals1) << endl;

}