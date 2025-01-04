#include "../common_headers.h"

int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int index = -1, min_dist = INT_MAX;
    
    for(int i=0; i<points.size(); i++){
        int cur_x = points[i][0], cur_y = points[i][1];
        
        if(cur_x == x || cur_y == y){
            int cur_dist = abs(cur_x - x) + abs(cur_y - y);
            if(cur_dist < min_dist){
                min_dist = cur_dist;
                index = i;
            }
        }
    }
    
    return index;
    
}


int main(){
    
}