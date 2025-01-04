#include "../common_headers.h"

// method 1: one map
// TC: O(nlogn)
int minMeetingRooms1(vector<vector<int>>& intervals) {
    
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

// method 2: 2 vectors
int minMeetingRooms2(vector<vector<int>>& intervals) {
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


// method 3: 1 priority queue
// TC: O(nlogn)
// SC: O(n)
int minMeetingRooms3(vector<vector<int>>& intervals) {
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