#include "../common_headers.h"

// TC: O(n log(n))
bool canAttendMeetings(vector<vector<int>>& intervals) {
    if(!intervals.size()) return true;
    sort(intervals.begin(), intervals.end());
    for(int i=0; i<intervals.size()-1; i++){
        if(intervals[i+1][0] < intervals[i][1]) return false;
    }
    
    return true;
}