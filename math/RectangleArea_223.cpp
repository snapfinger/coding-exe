int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int w_olp = min(ax2, bx2) - max(ax1, bx1);
    int h_olp = min(ay2, by2) - max(ay1, by1);
    int area_overlap = 0;
    
    if(w_olp > 0 && h_olp >0){
        area_overlap = w_olp * h_olp;
    }
    
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);
    
    return area1 + area2 - area_overlap;
}