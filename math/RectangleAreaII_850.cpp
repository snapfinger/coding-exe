#include "../common_headers.h"


int rectangleArea(vector<vector<int>>& rectangles) {
    long res = 0, pre_x = 0, height = 0, start = 0, cnt = 0, M = 1e9 + 7;
    map<int, vector<pair<int, int>>> groupMap;
    map<int, int> cntMap;
    for (auto &a : rectangles) {
        groupMap[a[0]].push_back({a[1], 1});
        groupMap[a[0]].push_back({a[3], -1});
        groupMap[a[2]].push_back({a[1], -1});
        groupMap[a[2]].push_back({a[3], 1});
    }

    printDict(groupMap);

    for (auto &group : groupMap) {
        cout << "group.first: " << group.first << endl;
        res = (res + (group.first - pre_x) * height) % M;
        cout << "area = " << res << endl;
        for (auto &a : group.second) {
            cntMap[a.first] += a.second;
        }

        cout << "cntMap: " << endl;
        for(auto &a: cntMap){
            cout << a.first << ": " << a.second << endl;
        }

        height = 0, start = 0, cnt = 0;
        for (auto &a : cntMap) {
            if (cnt == 0){
                start = a.first;
                cout << "start: " << start << endl;
            }
            cnt += a.second;
            cout << "cnt: " << cnt << endl;
            if (cnt == 0){
                height += a.first - start;
                cout << "height: " << height << endl;
            }
        }
        pre_x = group.first;
        cout << "pre_x= " << pre_x << "\n" << endl;
    }
    return res;
}

int main(){
    // vector<vector<int>> rec1 = {{0,0,2,2}, {1,0,2,3}, {1,0,3,1}};
     vector<vector<int>> rec1 = {{1,0,2,3},{1,0,3,1}};
     int ans = rectangleArea(rec1);
     cout << "ans: " << ans << endl;
}